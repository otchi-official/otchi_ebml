//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PIXELCROPRIGHT_H
#define INCLUDE_OTCHI_EBML_PIXELCROPRIGHT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId PixelCropRightId = 0x54DD;

    class PixelCropRight : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PixelCropRight";
        }

        [[nodiscard]] EBMLId getId() const override {
            return PixelCropRightId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\PixelCropRight)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PixelCropRightFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new PixelCropRight(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PIXELCROPRIGHT_H
