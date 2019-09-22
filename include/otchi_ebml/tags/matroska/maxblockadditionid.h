//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_MAXBLOCKADDITIONID_H
#define INCLUDE_OTCHI_EBML_MAXBLOCKADDITIONID_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId MaxBlockAdditionIDId = 0x55EE;

    class MaxBlockAdditionID : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "MaxBlockAdditionID";
        }

        [[nodiscard]] EBMLId getId() const override {
            return MaxBlockAdditionIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return R"(1*1(\Segment\Tracks\TrackEntry\MaxBlockAdditionID))";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class MaxBlockAdditionIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new MaxBlockAdditionID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_MAXBLOCKADDITIONID_H