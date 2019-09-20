//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TIMESTAMPSCALE_H
#define INCLUDE_OTCHI_EBML_TIMESTAMPSCALE_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId TimestampScaleId = 0x2AD7B1;

    class TimestampScale : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TimestampScale";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TimestampScaleId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Info\\TimestampScale)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TimestampScaleFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new TimestampScale(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TIMESTAMPSCALE_H
