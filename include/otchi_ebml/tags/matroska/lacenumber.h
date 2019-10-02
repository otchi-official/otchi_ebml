//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_LACENUMBER_H
#define INCLUDE_OTCHI_EBML_LACENUMBER_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id LaceNumberId = 0xCC;

    class LaceNumber : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "LaceNumber";
        }

        [[nodiscard]] ebml_id getId() const override {
            return LaceNumberId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\BlockGroup\\Slices\\TimeSlice\\LaceNumber)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class LaceNumberFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new LaceNumber(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_LACENUMBER_H
