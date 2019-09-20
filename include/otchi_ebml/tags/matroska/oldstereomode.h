//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_OLDSTEREOMODE_H
#define INCLUDE_OTCHI_EBML_OLDSTEREOMODE_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId OldStereoModeId = 0x53B9;

    class OldStereoMode : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "OldStereoMode";
        }

        [[nodiscard]] EBMLId getId() const override {
            return OldStereoModeId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\OldStereoMode)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class OldStereoModeFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new OldStereoMode(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_OLDSTEREOMODE_H
