//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CUEDURATION_H
#define INCLUDE_OTCHI_EBML_CUEDURATION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id CueDurationId = 0xB2;

    class CueDuration : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CueDuration";
        }

        [[nodiscard]] ebml_id getId() const override {
            return CueDurationId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cues\\CuePoint\\CueTrackPositions\\CueDuration)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CueDurationFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new CueDuration(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CUEDURATION_H
