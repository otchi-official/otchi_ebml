//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FLAGLACING_H
#define INCLUDE_OTCHI_EBML_FLAGLACING_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id FlagLacingId = 0x9C;

    class FlagLacing : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FlagLacing";
        }

        [[nodiscard]] ebml_id getId() const override {
            return FlagLacingId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\FlagLacing)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FlagLacingFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new FlagLacing(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FLAGLACING_H
