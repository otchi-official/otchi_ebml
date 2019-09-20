//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_EBML_READ_VERSION_H
#define INCLUDE_OTCHI_EBML_EBML_READ_VERSION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId EBMLReadVersionId = 0x42F7;

    class EBMLReadVersion : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EBMLReadVersion";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EBMLReadVersionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\EBMLReadVersion)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "The minimum EBML version an EBML Reader has to support to read this EBML Document. The EBMLReadVersion Element MUST be less than or equal to EBMLVersion.";
        }
    };

    class EBMLReadVersionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new EBMLReadVersion(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_READ_VERSION_H
