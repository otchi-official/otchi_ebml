//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_EDITIONENTRY_H
#define INCLUDE_OTCHI_EBML_EDITIONENTRY_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id EditionEntryId = 0x45B9;

    class EditionEntry : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EditionEntry";
        }

        [[nodiscard]] ebml_id getId() const override {
            return EditionEntryId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Chapters\\EditionEntry)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class EditionEntryFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new EditionEntry(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EDITIONENTRY_H
