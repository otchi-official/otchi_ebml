//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPTERDISPLAY_H
#define INCLUDE_OTCHI_EBML_CHAPTERDISPLAY_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id ChapterDisplayId = 0x80;

    class ChapterDisplay : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapterDisplay";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapterDisplayId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterDisplay)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapterDisplayFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapterDisplay(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPTERDISPLAY_H
