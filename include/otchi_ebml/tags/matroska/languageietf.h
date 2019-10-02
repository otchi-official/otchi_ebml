//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_LANGUAGEIETF_H
#define INCLUDE_OTCHI_EBML_LANGUAGEIETF_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id LanguageIETFId = 0x22B59D;

    class LanguageIETF : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "LanguageIETF";
        }

        [[nodiscard]] ebml_id getId() const override {
            return LanguageIETFId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\LanguageIETF)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class LanguageIETFFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new LanguageIETF(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_LANGUAGEIETF_H
