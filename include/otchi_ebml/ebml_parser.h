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

#include "otchi_ebml/elements/ebml_element_factory.h"
#include "otchi_ebml/elements/ebml_document.h"
#include "otchi_ebml/tags/ebml_tags.h"

namespace otchi_ebml {
    class EBMLParser {
        // To validate the parsed document, make sure to add all possible tags that could appear.
        bool shouldValidate_ = false;
        std::unordered_map<EBMLId, IEBMLElementFactory*> bodyTags;
        std::unordered_map<EBMLId, IEBMLElementFactory*> headTags = EBMLTags::getEbmlHeadTags();
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

        int readId(int *s = nullptr) {
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

        long long readSize(int *s = nullptr) {
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

        EBMLDocument parse(std::streamoff from = 0, std::streamoff to = -1) {
            if (to < 0) {
                to = size();
            }

            fs_.seekg(from, std::ios_base::beg);

            EBMLDocument document{};
        }

        EBMLHead parseHead() {

        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_PARSER_H
