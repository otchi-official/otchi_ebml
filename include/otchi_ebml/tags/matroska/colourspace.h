//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_COLOURSPACE_H
#define INCLUDE_OTCHI_EBML_COLOURSPACE_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId ColourSpaceId = 0x2EB524;

    class ColourSpace : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ColourSpace";
        }

        [[nodiscard]] EBMLId getId() const override {
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
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ColourSpace(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_COLOURSPACE_H
