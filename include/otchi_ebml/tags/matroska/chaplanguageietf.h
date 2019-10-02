//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPLANGUAGEIETF_H
#define INCLUDE_OTCHI_EBML_CHAPLANGUAGEIETF_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id ChapLanguageIETFId = 0x437D;

    class ChapLanguageIETF : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapLanguageIETF";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapLanguageIETFId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterDisplay\\ChapLanguageIETF)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapLanguageIETFFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapLanguageIETF(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPLANGUAGEIETF_H
