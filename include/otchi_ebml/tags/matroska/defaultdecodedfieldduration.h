//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DEFAULTDECODEDFIELDDURATION_H
#define INCLUDE_OTCHI_EBML_DEFAULTDECODEDFIELDDURATION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id DefaultDecodedFieldDurationId = 0x234E7A;

    class DefaultDecodedFieldDuration : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DefaultDecodedFieldDuration";
        }

        [[nodiscard]] ebml_id getId() const override {
            return DefaultDecodedFieldDurationId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\DefaultDecodedFieldDuration)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DefaultDecodedFieldDurationFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new DefaultDecodedFieldDuration(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DEFAULTDECODEDFIELDDURATION_H
