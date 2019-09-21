//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CUES_H
#define INCLUDE_OTCHI_EBML_CUES_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId CuesId = 0x1C53BB6B;

    class Cues : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Cues";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CuesId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cues)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CuesFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Cues(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CUES_H
