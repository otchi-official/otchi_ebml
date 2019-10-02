//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_BLOCKMORE_H
#define INCLUDE_OTCHI_EBML_BLOCKMORE_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id BlockMoreId = 0xA6;

    class BlockMore : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "BlockMore";
        }

        [[nodiscard]] ebml_id getId() const override {
            return BlockMoreId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Cluster\\BlockGroup\\BlockAdditions\\BlockMore)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class BlockMoreFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new BlockMore(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_BLOCKMORE_H
