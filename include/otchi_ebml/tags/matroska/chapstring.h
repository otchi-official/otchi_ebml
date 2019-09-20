//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPSTRING_H
#define INCLUDE_OTCHI_EBML_CHAPSTRING_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi_ebml {

    constexpr EBMLId ChapStringId = 0x85;

    class ChapString : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapString";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ChapStringId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterDisplay\\ChapString)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapStringFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ChapString(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPSTRING_H
