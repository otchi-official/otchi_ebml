//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SLICES_H
#define INCLUDE_OTCHI_EBML_SLICES_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId SlicesId = 0x8E;

    class Slices : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Slices";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SlicesId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\BlockGroup\\Slices)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SlicesFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Slices(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SLICES_H