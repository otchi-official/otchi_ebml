//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPCOUNTRY_H
#define INCLUDE_OTCHI_EBML_CHAPCOUNTRY_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id ChapCountryId = 0x437E;

    class ChapCountry : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapCountry";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapCountryId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterDisplay\\ChapCountry)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapCountryFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapCountry(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPCOUNTRY_H
