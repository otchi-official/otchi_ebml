//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKPLANE_H
#define INCLUDE_OTCHI_EBML_TRACKPLANE_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id TrackPlaneId = 0xE4;

    class TrackPlane : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackPlane";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TrackPlaneId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Tracks\\TrackEntry\\TrackOperation\\TrackCombinePlanes\\TrackPlane)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackPlaneFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TrackPlane(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKPLANE_H
