//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PIXELCROPLEFT_H
#define INCLUDE_OTCHI_EBML_PIXELCROPLEFT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId PixelCropLeftId = 0x54CC;

    class PixelCropLeft : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PixelCropLeft";
        }

        [[nodiscard]] EBMLId getId() const override {
            return PixelCropLeftId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\PixelCropLeft)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PixelCropLeftFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new PixelCropLeft(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PIXELCROPLEFT_H
