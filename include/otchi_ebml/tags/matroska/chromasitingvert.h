//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHROMASITINGVERT_H
#define INCLUDE_OTCHI_EBML_CHROMASITINGVERT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id ChromaSitingVertId = 0x55B8;

    class ChromaSitingVert : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChromaSitingVert";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChromaSitingVertId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\ChromaSitingVert)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChromaSitingVertFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChromaSitingVert(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHROMASITINGVERT_H
