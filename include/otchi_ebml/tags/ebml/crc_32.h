//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CRC_32_H
#define INCLUDE_OTCHI_EBML_CRC_32_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId CRC_32Id = 0xBF;

    class CRC_32 : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CRC-32";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CRC_32Id;
        }

        [[nodiscard]] std::string getPath() const override {
            return "*1((1*\\)\\CRC-32)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "The CRC-32 Element contains a 32-bit Cyclic Redundancy Check value of all the Element Data of the Parent Element as stored except for the CRC-32 Element itself. When the CRC-32 Element is present, the CRC-32 Element MUST be the first ordered EBML Element within its Parent Element for easier reading. All Top-Level Elements of an EBML Document that are Master Elements SHOULD include a CRC-32 Element as a Child Element. The CRC in use is the IEEE-CRC-32 algorithm as used in the [@!ISO.3309.1979] standard and in section 8.1.1.6.2 of [@!ITU.V42.1994], with initial value of 0xFFFFFFFF. The CRC value MUST be computed on a little endian bitstream and MUST use little endian storage.";
        }
    };

    class CRC_32Factory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CRC_32(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CRC_32_H
