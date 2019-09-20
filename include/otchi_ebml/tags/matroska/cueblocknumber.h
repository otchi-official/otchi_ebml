//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CUEBLOCKNUMBER_H
#define INCLUDE_OTCHI_EBML_CUEBLOCKNUMBER_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId CueBlockNumberId = 0x5378;

    class CueBlockNumber : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CueBlockNumber";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CueBlockNumberId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cues\\CuePoint\\CueTrackPositions\\CueBlockNumber)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CueBlockNumberFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CueBlockNumber(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CUEBLOCKNUMBER_H
