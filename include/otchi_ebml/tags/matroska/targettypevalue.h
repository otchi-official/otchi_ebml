//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TARGETTYPEVALUE_H
#define INCLUDE_OTCHI_EBML_TARGETTYPEVALUE_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId TargetTypeValueId = 0x68CA;

    class TargetTypeValue : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TargetTypeValue";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TargetTypeValueId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tags\\Tag\\Targets\\TargetTypeValue)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TargetTypeValueFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new TargetTypeValue(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TARGETTYPEVALUE_H
