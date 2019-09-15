//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_STRING_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_STRING_H

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    template<>
    class EBMLElement<EBMLType::kString> : public EBMLBaseElement {
        std::optional<std::string> value_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kString;
        }

        void decode(std::ifstream ifstream) override {
            auto buffer = new char[getContentSize()];
            ifstream.read(buffer, getContentSize());
            buffer[getContentSize()] = '\0';
            std::string s{buffer};
            value_ = s;
        }

        [[nodiscard]] std::string getValue() const {
            if (value_ == std::nullopt)
                throw NotInitialized("Trying to get value of object before it was decoded");
            return value_.value();
        }
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_STRING_H
