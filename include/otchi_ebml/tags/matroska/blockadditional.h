//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_BLOCKADDITIONAL_H
#define INCLUDE_OTCHI_EBML_BLOCKADDITIONAL_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId BlockAdditionalId = 0xA5;

    class BlockAdditional : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "BlockAdditional";
        }

        [[nodiscard]] EBMLId getId() const override {
            return BlockAdditionalId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Cluster\\BlockGroup\\BlockAdditions\\BlockMore\\BlockAdditional)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class BlockAdditionalFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new BlockAdditional(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_BLOCKADDITIONAL_H
