//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRICKTRACKSEGMENTUID_H
#define INCLUDE_OTCHI_EBML_TRICKTRACKSEGMENTUID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id TrickTrackSegmentUIDId = 0xC1;

    class TrickTrackSegmentUID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrickTrackSegmentUID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TrickTrackSegmentUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\TrickTrackSegmentUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrickTrackSegmentUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TrickTrackSegmentUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRICKTRACKSEGMENTUID_H
