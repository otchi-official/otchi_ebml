//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FLAGDEFAULT_H
#define INCLUDE_OTCHI_EBML_FLAGDEFAULT_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id FlagDefaultId = 0x88;

    class FlagDefault : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FlagDefault";
        }

        [[nodiscard]] ebml_id getId() const override {
            return FlagDefaultId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\FlagDefault)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FlagDefaultFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new FlagDefault(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FLAGDEFAULT_H
