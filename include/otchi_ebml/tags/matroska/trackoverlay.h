//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKOVERLAY_H
#define INCLUDE_OTCHI_EBML_TRACKOVERLAY_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId TrackOverlayId = 0x6FAB;

    class TrackOverlay : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackOverlay";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TrackOverlayId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tracks\\TrackEntry\\TrackOverlay)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackOverlayFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new TrackOverlay(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKOVERLAY_H
