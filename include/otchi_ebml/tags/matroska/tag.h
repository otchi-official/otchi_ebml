//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAG_H
#define INCLUDE_OTCHI_EBML_TAG_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id TagId = 0x7373;

    class Tag : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Tag";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TagId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Tags\\Tag)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new Tag(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAG_H
