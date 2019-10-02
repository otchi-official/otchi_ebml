//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_BLOCKADDITIONS_H
#define INCLUDE_OTCHI_EBML_BLOCKADDITIONS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id BlockAdditionsId = 0x75A1;

    class BlockAdditions : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "BlockAdditions";
        }

        [[nodiscard]] ebml_id getId() const override {
            return BlockAdditionsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\BlockGroup\\BlockAdditions)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class BlockAdditionsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new BlockAdditions(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_BLOCKADDITIONS_H
