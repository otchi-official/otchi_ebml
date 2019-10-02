//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPPROCESSCOMMAND_H
#define INCLUDE_OTCHI_EBML_CHAPPROCESSCOMMAND_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id ChapProcessCommandId = 0x6911;

    class ChapProcessCommand : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapProcessCommand";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapProcessCommandId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapProcess\\ChapProcessCommand)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapProcessCommandFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapProcessCommand(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPPROCESSCOMMAND_H
