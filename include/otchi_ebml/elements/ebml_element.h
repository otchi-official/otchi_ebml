//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_H

// Abstract Base class for EBML Values

#include <string>
#include <unordered_map>
#include <optional>
#include <utility>
#include <fstream>
#include <iostream>
#include <cassert>
#include <exception>

#include "ebml_type.h"
#include "otchi_ebml/types/ebml_alias.h"
#include "otchi_ebml/types/ebml_path.h"

namespace otchi_ebml {

    class EBMLBaseElement {

        EBMLSize idSize_;
        EBMLSize dataSize_;
        EBMLSize contentSize_;
        EBMLPosition position_;
        EBMLBaseElement *parent_;

        // TODO: Parse path

    public:

        EBMLBaseElement(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                        EBMLPosition position, EBMLBaseElement *parent = nullptr) :
                idSize_{idSize}, dataSize_{dataSize}, contentSize_{dataContentSize}, position_{position},
                parent_{parent} {}

        [[nodiscard]] EBMLSize elementSize() const {
            return idSize_ + dataSize_ + contentSize_;
        }

        // Abstract methods
        [[nodiscard]] virtual EBMLType getType() = 0;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual EBMLId getId() const = 0;

        [[nodiscard]] virtual std::string getPath() const = 0;

        // Virtual Methods

        [[nodiscard]] virtual bool validateValue() const { return true; }

        [[nodiscard]] std::optional<int> minOccurs() const {
            if (getPath().at(0) == '*')
                return std::nullopt;
            int n = std::stoi(getPath().substr(0, 1));
            return n;
        }

        [[nodiscard]] virtual std::optional<int> maxOccurs() const {
            int asteriskPos = getPath().at(0) == '*' ? 0 : 1;
            assert(getPath().at(asteriskPos) == '*');

            try {
                int n = std::stoi(getPath().substr(asteriskPos + 1, asteriskPos + 1));
                return n;
            } catch (const std::exception &e) {
                return std::nullopt;
            }
        }

        [[nodiscard]] virtual std::string getDescription() const { return ""; }

        virtual void print() const {
            std::cout << getName();
        }

        // TODO ENCODE
        // TODO: Validate

        virtual void decode(std::ifstream &ifstream) = 0;

        // getters
        [[nodiscard]] EBMLSize getIdSize() const { return idSize_; }

        [[nodiscard]] EBMLSize getDataSize() const { return dataSize_; }

        [[nodiscard]] EBMLSize getContentSize() const { return contentSize_; }

        [[nodiscard]] EBMLPosition getPosition() const { return position_; }

    };

    template<const EBMLType type>
    class EBMLElement : EBMLBaseElement {
        using EBMLBaseElement::EBMLBaseElement;
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
