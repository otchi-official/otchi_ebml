//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPTERSEGMENTUID_H
#define INCLUDE_OTCHI_EBML_CHAPTERSEGMENTUID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId ChapterSegmentUIDId = 0x6E67;

    class ChapterSegmentUID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapterSegmentUID";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ChapterSegmentUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterSegmentUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapterSegmentUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ChapterSegmentUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPTERSEGMENTUID_H
