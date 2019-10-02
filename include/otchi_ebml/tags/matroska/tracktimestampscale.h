//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKTIMESTAMPSCALE_H
#define INCLUDE_OTCHI_EBML_TRACKTIMESTAMPSCALE_H

#include "otchi_ebml/elements/ebml_element_double.h"

namespace otchi {

    constexpr ebml_id TrackTimestampScaleId = 0x23314F;

    class TrackTimestampScale : public EBMLElement<EBMLType::kDouble> {
    public:
        using EBMLElement<EBMLType::kDouble>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackTimestampScale";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TrackTimestampScaleId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\TrackTimestampScale)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackTimestampScaleFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TrackTimestampScale(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKTIMESTAMPSCALE_H
