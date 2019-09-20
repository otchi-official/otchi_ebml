//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DEFAULTDURATION_H
#define INCLUDE_OTCHI_EBML_DEFAULTDURATION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DefaultDurationId = 0x23E383;

    class DefaultDuration : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DefaultDuration";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DefaultDurationId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\DefaultDuration)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DefaultDurationFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DefaultDuration(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DEFAULTDURATION_H
