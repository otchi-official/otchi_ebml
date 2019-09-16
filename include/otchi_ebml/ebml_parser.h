//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_PARSER_H
#define INCLUDE_OTCHI_EBML_EBML_PARSER_H

#include <iostream>
#include <unordered_map>
#include <filesystem>
#include <utility>
#include <otchi_ebml/tags/ebml_head.h>
#include <cassert>
#include <type_traits>
#include <stack>
#include <vector>

#include "otchi_ebml/elements/ebml_element_factory.h"
#include "otchi_ebml/elements/ebml_document.h"
#include "otchi_ebml/tags/ebml_tags.h"

namespace otchi_ebml {
    class EBMLParser {
        // To validate the parsed document, make sure to add all possible tags that could appear.
        bool shouldValidate_ = false;
        std::unordered_map<EBMLId, IEBMLElementFactory *> tagsToParse = EBMLTags::getEbmlHeadTags();
        std::unordered_map<EBMLId, IEBMLElementFactory *> headTags = EBMLTags::getEbmlHeadTags();
        std::filesystem::path path_;
        std::ifstream fs_;
        std::streampos size_;

    public:

        explicit EBMLParser(std::filesystem::path path) : path_{std::move(path)} {
            openStream();
        }

        void openStream() {
            if (!fs_.is_open()) {
                fs_.open(path_, std::ios::binary | std::ios::ate);
                size_ = fs_.tellg();
                fs_.seekg(0, std::ios::beg);
            } else {
                std::cout << "File already open" << std::endl;
            }
        }

        void close() {
            if (fs_.is_open())
                fs_.close();
        }

        [[nodiscard]] std::streampos size() const {
            return size_;
        }

        std::streamoff position() {
            return fs_.tellg();
        }

        int readId(EBMLSize *s = nullptr) {
            unsigned char initialBit;
            fs_.read(reinterpret_cast<char *>(&initialBit), 1);

            unsigned int size{0};
            if (initialBit & 0b10000000u) {
                size = 0;
            } else if (initialBit & 0b01000000u) {
                size = 1;
            } else if (initialBit & 0b00100000u) {
                size = 2;
            } else if (initialBit & 0b00010000u) {
                size = 3;
            } else {
                throw std::runtime_error("Invalid element ID");
            }

            if (s)
                *s = static_cast<int>(size + 1);

            int value{initialBit << 8u * size};
            auto *buffer = new unsigned char[size];
            fs_.read(reinterpret_cast<char *>(buffer), size);
            for (unsigned int i = 0; i < size; i++) {
                value += buffer[i] << 8u * (size - i - 1);
            }
            return value;
        }

        long long readSize(EBMLSize *s = nullptr) {
            unsigned char initialBit;
            fs_.read(reinterpret_cast<char *>(&initialBit), 1);

            long long value{0};
            unsigned int size{0};

            if (initialBit & 0b10000000u) {
                value += (initialBit & 0b01111111u);
            } else if (initialBit & 0b01000000u) {
                size = 1;
                value += (initialBit & 0b00111111u) << 8u * size;
            } else if (initialBit & 0b00100000u) {
                size = 2;
                value += (initialBit & 0b00011111u) << 8u * size;
            } else if (initialBit & 0b00010000u) {
                size = 3;
                value += (initialBit & 0b00001111u) << 8u * size;
            } else if (initialBit & 0b00001000u) {
                size = 4;
                value += (initialBit & 0b00000111u) << 8u * size;
            } else if (initialBit & 0b00000100u) {
                size = 5;
                value += (initialBit & 0b00000011u) << 8u * size;
            } else if (initialBit & 0b00000010u) {
                size = 6;
                value += (initialBit & 0b00000001u) << 8u * size;
            } else if (initialBit & 0b00000001u) {
                size = 7;
            } else {
                throw std::length_error("Undefined element size");
            }

            if (s)
                *s = static_cast<int>(size + 1);

            auto buffer = new unsigned char[size];
            fs_.read(reinterpret_cast<char *>(buffer), size);
            for (unsigned int i = 0; i < size; i++) {
                value += buffer[i] << 8u * (size - i - 1);
            }
            return value;
        }

        std::vector<EBMLBaseElement *> parse(std::streamoff from = 0, std::streamoff to = -1) {
            if (to < 0) {
                to = size();
            }

            fs_.seekg(from, std::ios_base::beg);

            std::vector<EBMLBaseElement *> masterNodes{};
            std::stack<EBMLElement<EBMLType::kMaster> *> parentStack{};

            while (fs_.tellg() < to) {
                std::cout << "Current position: " << std::hex << fs_.tellg() << std::endl;
                auto node = parseNode();

                if (!node) {
                    continue;
                }

                std::cout << "Found " << node->getName() << std::endl;

                if (parentStack.empty()) {
                    if (dynamic_cast<EBMLElement<EBMLType::kMaster>*>(node) == nullptr) {
                        std::cerr << "Root nodes have to be a master tag" << std::endl;
                    }
                    masterNodes.push_back(node);
                    parentStack.push(dynamic_cast<EBMLElement<EBMLType ::kMaster>*>(node));
                    continue;
                }

                parentStack.top()->append(node);

                if (!std::is_base_of<EBMLElement<EBMLType::kMaster>, decltype(node)>::value) {
                    auto parentEnd = parentStack.top()->getPosition() + parentStack.top()->elementSize();
                    auto nodeEnd = node->getPosition() + node->elementSize();
                    if (parentEnd == nodeEnd) {
                        std::cout << "Exact" << std::endl;
                        parentStack.pop();
                    } else if (parentEnd < nodeEnd) {
                        std::cout << "Something went wrong" << std::endl;
                    }
                }

            }

            return masterNodes;
        }

        EBMLBaseElement *parseNode() {
            EBMLPosition position = this->position();
            EBMLId id;
            EBMLSize idSize;
            EBMLSize contentSize;
            EBMLSize dataSize;

            try {
                id = readId(&idSize);
            } catch (std::runtime_error &error) {
                std::cerr << error.what() << std::endl;
                return nullptr;
            }

            contentSize = readSize(&dataSize);
            if (contentSize == 0b011111111) {
                std::cerr << "Don't know how to handle element with unknown contentSize: " << contentSize << std::endl;
            }

            if (tagsToParse.count(id) == 0) {
                fs_.seekg(contentSize + fs_.tellg());
                std::cout << "Skipping tag with id: " << std::hex << id << std::endl;
                return nullptr;
            }

            IEBMLElementFactory *factory = tagsToParse[id];
            EBMLBaseElement *element = factory->create(idSize, dataSize, contentSize, position);
            element->decode(fs_);
            return element;
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_PARSER_H
