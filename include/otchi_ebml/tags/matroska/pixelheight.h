//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PIXELHEIGHT_H
#define INCLUDE_OTCHI_EBML_PIXELHEIGHT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id PixelHeightId = 0xBA;

    class PixelHeight : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PixelHeight";
        }

        [[nodiscard]] ebml_id getId() const override {
            return PixelHeightId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\Video\\PixelHeight)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PixelHeightFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new PixelHeight(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PIXELHEIGHT_H
