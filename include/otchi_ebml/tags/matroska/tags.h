//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAGS_H
#define INCLUDE_OTCHI_EBML_TAGS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId TagsId = 0x1254C367;

    class Tags : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Tags";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TagsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tags)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Tags(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAGS_H
