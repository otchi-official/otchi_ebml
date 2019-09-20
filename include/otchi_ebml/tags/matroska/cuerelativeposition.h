//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CUERELATIVEPOSITION_H
#define INCLUDE_OTCHI_EBML_CUERELATIVEPOSITION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId CueRelativePositionId = 0xF0;

    class CueRelativePosition : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CueRelativePosition";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CueRelativePositionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cues\\CuePoint\\CueTrackPositions\\CueRelativePosition)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CueRelativePositionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CueRelativePosition(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CUERELATIVEPOSITION_H
