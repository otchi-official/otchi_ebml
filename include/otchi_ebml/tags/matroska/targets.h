//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TARGETS_H
#define INCLUDE_OTCHI_EBML_TARGETS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id TargetsId = 0x63C0;

    class Targets : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Targets";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TargetsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tags\\Tag\\Targets)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TargetsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new Targets(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TARGETS_H
