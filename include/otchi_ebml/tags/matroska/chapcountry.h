//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPCOUNTRY_H
#define INCLUDE_OTCHI_EBML_CHAPCOUNTRY_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi_ebml {

    constexpr EBMLId ChapCountryId = 0x437E;

    class ChapCountry : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapCountry";
        }

        [[nodiscard]] EBMLId getId() const override {
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
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ChapCountry(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPCOUNTRY_H
