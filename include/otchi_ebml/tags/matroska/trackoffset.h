//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKOFFSET_H
#define INCLUDE_OTCHI_EBML_TRACKOFFSET_H

#include "otchi_ebml/elements/ebml_element_int.h"

namespace otchi_ebml {

    constexpr EBMLId TrackOffsetId = 0x537F;

    class TrackOffset : public EBMLElement<EBMLType::kSInt> {
    public:
        using EBMLElement<EBMLType::kSInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackOffset";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TrackOffsetId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\TrackOffset)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackOffsetFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new TrackOffset(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKOFFSET_H
