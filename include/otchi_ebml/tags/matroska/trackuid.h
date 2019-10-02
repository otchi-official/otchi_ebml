//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKUID_H
#define INCLUDE_OTCHI_EBML_TRACKUID_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id TrackUIDId = 0x73C5;

    class TrackUID : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackUID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TrackUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\TrackUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TrackUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKUID_H
