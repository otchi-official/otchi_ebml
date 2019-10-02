//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_EBMLMAXIDLENGTH_H
#define INCLUDE_OTCHI_EBML_EBMLMAXIDLENGTH_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id EBMLMaxIDLengthId = 0x42F2;

    class EBMLMaxIDLength : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EBMLMaxIDLength";
        }

        [[nodiscard]] ebml_id getId() const override {
            return EBMLMaxIDLengthId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\EBMLMaxIDLength)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class EBMLMaxIDLengthFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new EBMLMaxIDLength(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBMLMAXIDLENGTH_H
