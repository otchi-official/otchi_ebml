//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_EDITIONFLAGHIDDEN_H
#define INCLUDE_OTCHI_EBML_EDITIONFLAGHIDDEN_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId EditionFlagHiddenId = 0x45BD;

    class EditionFlagHidden : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EditionFlagHidden";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EditionFlagHiddenId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Chapters\\EditionEntry\\EditionFlagHidden)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class EditionFlagHiddenFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new EditionFlagHidden(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EDITIONFLAGHIDDEN_H
