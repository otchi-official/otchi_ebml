//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DISCARDPADDING_H
#define INCLUDE_OTCHI_EBML_DISCARDPADDING_H

#include "otchi_ebml/elements/ebml_element_int.h"

namespace otchi {

    constexpr ebml_id DiscardPaddingId = 0x75A2;

    class DiscardPadding : public EBMLElement<EBMLType::kSInt> {
    public:
        using EBMLElement<EBMLType::kSInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DiscardPadding";
        }

        [[nodiscard]] ebml_id getId() const override {
            return DiscardPaddingId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\BlockGroup\\DiscardPadding)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DiscardPaddingFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new DiscardPadding(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DISCARDPADDING_H
