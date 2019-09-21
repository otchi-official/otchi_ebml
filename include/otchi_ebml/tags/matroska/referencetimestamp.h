//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_REFERENCETIMESTAMP_H
#define INCLUDE_OTCHI_EBML_REFERENCETIMESTAMP_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId ReferenceTimestampId = 0xCA;

    class ReferenceTimestamp : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ReferenceTimestamp";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ReferenceTimestampId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Cluster\\BlockGroup\\ReferenceFrame\\ReferenceTimestamp)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ReferenceTimestampFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ReferenceTimestamp(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_REFERENCETIMESTAMP_H
