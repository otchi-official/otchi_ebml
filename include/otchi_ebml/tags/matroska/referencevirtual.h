//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_REFERENCEVIRTUAL_H
#define INCLUDE_OTCHI_EBML_REFERENCEVIRTUAL_H

#include "otchi_ebml/elements/ebml_element_int.h"

namespace otchi {

    constexpr ebml_id ReferenceVirtualId = 0xFD;

    class ReferenceVirtual : public EBMLElement<EBMLType::kSInt> {
    public:
        using EBMLElement<EBMLType::kSInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ReferenceVirtual";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ReferenceVirtualId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\BlockGroup\\ReferenceVirtual)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ReferenceVirtualFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ReferenceVirtual(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_REFERENCEVIRTUAL_H
