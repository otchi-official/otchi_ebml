//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEEKPREROLL_H
#define INCLUDE_OTCHI_EBML_SEEKPREROLL_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId SeekPreRollId = 0x56BB;

    class SeekPreRoll : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SeekPreRoll";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SeekPreRollId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\SeekPreRoll)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SeekPreRollFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new SeekPreRoll(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEEKPREROLL_H
