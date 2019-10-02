//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPTERSTRINGUID_H
#define INCLUDE_OTCHI_EBML_CHAPTERSTRINGUID_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi {

    constexpr ebml_id ChapterStringUIDId = 0x5654;

    class ChapterStringUID : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapterStringUID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapterStringUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterStringUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapterStringUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapterStringUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPTERSTRINGUID_H
