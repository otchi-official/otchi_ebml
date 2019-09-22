//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_COLOUR_H
#define INCLUDE_OTCHI_EBML_COLOUR_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId ColourId = 0x55B0;

    class Colour : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Colour";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ColourId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ColourFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Colour(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_COLOUR_H