//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKS_H
#define INCLUDE_OTCHI_EBML_TRACKS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id TracksId = 0x1654AE6B;

    class Tracks : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Tracks";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TracksId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tracks)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TracksFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new Tracks(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKS_H
