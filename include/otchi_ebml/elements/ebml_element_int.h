//
// Created by jorge on 9/13/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_INT_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_INT_H

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    template<>
    class EBMLElement<EBMLType::kSInt> : public EBMLBaseElement {
        std::optional<int> value_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kSInt;
        }

        void decode(std::ifstream ifstream) override {
            if (getContentSize() > 8 || getContentSize() < 1)
                throw std::range_error("Length is out of range");

            auto buffer = new unsigned char[getContentSize()];
            ifstream.read(reinterpret_cast<char *>(buffer), getContentSize());
            int value{0};
            for (unsigned int i = 0; i < getContentSize(); i++) {
                value += buffer[i] << 8u * (getContentSize() - i - 1);
            }

            // Make signed
            unsigned int nbits = (8 - getContentSize()) + 8 * (getContentSize() - 1);
            if (value >= (1u << (nbits - 1))) {
                value -= static_cast<int>(1u << nbits);
            }

            value_ = value;
        }

        [[nodiscard]] int getValue() const {
            if (value_ == std::nullopt)
                throw NotInitialized("Trying to get value of object before it was decoded");
            return value_.value();
        }
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_INT_H
