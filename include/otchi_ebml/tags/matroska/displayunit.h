//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DISPLAYUNIT_H
#define INCLUDE_OTCHI_EBML_DISPLAYUNIT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DisplayUnitId = 0x54B2;

    class DisplayUnit : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DisplayUnit";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DisplayUnitId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\DisplayUnit)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DisplayUnitFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DisplayUnit(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DISPLAYUNIT_H
