//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FIELDORDER_H
#define INCLUDE_OTCHI_EBML_FIELDORDER_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id FieldOrderId = 0x9D;

    class FieldOrder : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FieldOrder";
        }

        [[nodiscard]] ebml_id getId() const override {
            return FieldOrderId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\Video\\FieldOrder)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FieldOrderFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new FieldOrder(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FIELDORDER_H
