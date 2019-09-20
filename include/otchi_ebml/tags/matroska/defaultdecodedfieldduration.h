//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DEFAULTDECODEDFIELDDURATION_H
#define INCLUDE_OTCHI_EBML_DEFAULTDECODEDFIELDDURATION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DefaultDecodedFieldDurationId = 0x234E7A;

    class DefaultDecodedFieldDuration : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DefaultDecodedFieldDuration";
        }

        [[nodiscard]] EBMLId getId() const override {
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
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DefaultDecodedFieldDuration(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DEFAULTDECODEDFIELDDURATION_H
