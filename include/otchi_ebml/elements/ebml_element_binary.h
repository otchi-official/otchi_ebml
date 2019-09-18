//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_BINARY_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_BINARY_H

#include <vector>

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    template<>
    class EBMLElement<EBMLType::kBinary> : public EBMLBaseElement {
        std::optional<std::vector<char>> value_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kBinary;
        }

        void decode(std::ifstream &ifstream) override {
            std::vector<char> vector;
            ifstream.read(&vector[0], getContentSize());
            value_ = vector;
        }

        [[nodiscard]] const std::vector<char> &getValue() const {
            if (value_ == std::nullopt)
                throw NotInitialized("Trying to get value of object before it was decoded");
            return value_.value();
        }
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_BINARY_H
