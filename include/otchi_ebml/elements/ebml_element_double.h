//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_DOUBLE_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_DOUBLE_H

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    template<>
    class EBMLElement<EBMLType::kDouble> : public EBMLBaseElement {
        std::optional<double> value_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kDouble;
        }

        void decode(std::ifstream ifstream) override {
            double d;
            ifstream.read(reinterpret_cast<char *>(&d), getContentSize());
            value_ = d;
        }

        [[nodiscard]] double getValue() const {
            if (value_ == std::nullopt)
                throw NotInitialized("Trying to get value of object before it was decoded");
            return value_.value();
        }
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_DOUBLE_H
