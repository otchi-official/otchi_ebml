//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_COLOURSPACE_H
#define INCLUDE_OTCHI_EBML_COLOURSPACE_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id ColourSpaceId = 0x2EB524;

    class ColourSpace : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ColourSpace";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ColourSpaceId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\ColourSpace)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ColourSpaceFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ColourSpace(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_COLOURSPACE_H
