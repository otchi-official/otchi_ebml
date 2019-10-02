//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_BLOCKVIRTUAL_H
#define INCLUDE_OTCHI_EBML_BLOCKVIRTUAL_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id BlockVirtualId = 0xA2;

    class BlockVirtual : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "BlockVirtual";
        }

        [[nodiscard]] ebml_id getId() const override {
            return BlockVirtualId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\BlockGroup\\BlockVirtual)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class BlockVirtualFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new BlockVirtual(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_BLOCKVIRTUAL_H
