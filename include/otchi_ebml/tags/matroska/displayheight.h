//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DISPLAYHEIGHT_H
#define INCLUDE_OTCHI_EBML_DISPLAYHEIGHT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DisplayHeightId = 0x54BA;

    class DisplayHeight : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DisplayHeight";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DisplayHeightId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\DisplayHeight)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DisplayHeightFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DisplayHeight(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DISPLAYHEIGHT_H
