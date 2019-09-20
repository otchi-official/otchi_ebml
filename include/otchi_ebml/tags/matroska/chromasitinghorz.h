//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHROMASITINGHORZ_H
#define INCLUDE_OTCHI_EBML_CHROMASITINGHORZ_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId ChromaSitingHorzId = 0x55B7;

    class ChromaSitingHorz : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChromaSitingHorz";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ChromaSitingHorzId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\ChromaSitingHorz)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChromaSitingHorzFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ChromaSitingHorz(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHROMASITINGHORZ_H
