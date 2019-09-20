//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_EBML_MAX_ID_LENGTH_H
#define INCLUDE_OTCHI_EBML_EBML_MAX_ID_LENGTH_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId EBMLMaxIdLengthId = 0x42F2;

    class EBMLMaxIdLength : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EBMLMaxIdLength";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EBMLMaxIdLengthId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\EBMLMaxIDLength)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "The EBMLMaxIDLength Element stores the maximum permitted length in octets of the Element IDs to be found within the EBML Body. An EBMLMaxIDLength Element value of four is RECOMMENDED, though larger values are allowed.";
        }
    };

    class EBMLMaxIdLengthFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new EBMLMaxIdLength(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_MAX_ID_LENGTH_H
