//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SIMPLETAG_H
#define INCLUDE_OTCHI_EBML_SIMPLETAG_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId SimpleTagId = 0x67C8;

    class SimpleTag : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SimpleTag";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SimpleTagId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Tags\\Tag(1*(\\SimpleTag)))";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SimpleTagFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new SimpleTag(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SIMPLETAG_H
