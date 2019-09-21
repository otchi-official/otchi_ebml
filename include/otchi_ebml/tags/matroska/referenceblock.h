//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_REFERENCEBLOCK_H
#define INCLUDE_OTCHI_EBML_REFERENCEBLOCK_H

#include "otchi_ebml/elements/ebml_element_int.h"

namespace otchi_ebml {

    constexpr EBMLId ReferenceBlockId = 0xFB;

    class ReferenceBlock : public EBMLElement<EBMLType::kSInt> {
    public:
        using EBMLElement<EBMLType::kSInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ReferenceBlock";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ReferenceBlockId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Cluster\\BlockGroup\\ReferenceBlock)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ReferenceBlockFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ReferenceBlock(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_REFERENCEBLOCK_H
