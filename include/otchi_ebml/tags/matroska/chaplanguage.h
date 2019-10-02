//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPLANGUAGE_H
#define INCLUDE_OTCHI_EBML_CHAPLANGUAGE_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id ChapLanguageId = 0x437C;

    class ChapLanguage : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapLanguage";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapLanguageId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapterDisplay\\ChapLanguage)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapLanguageFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapLanguage(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPLANGUAGE_H
