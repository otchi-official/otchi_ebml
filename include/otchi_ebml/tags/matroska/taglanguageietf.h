//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAGLANGUAGEIETF_H
#define INCLUDE_OTCHI_EBML_TAGLANGUAGEIETF_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id TagLanguageIETFId = 0x447B;

    class TagLanguageIETF : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TagLanguageIETF";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TagLanguageIETFId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tags\\Tag\\SimpleTag\\TagLanguageIETF)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagLanguageIETFFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TagLanguageIETF(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAGLANGUAGEIETF_H
