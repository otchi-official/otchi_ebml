//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPTERTRANSLATEID_H
#define INCLUDE_OTCHI_EBML_CHAPTERTRANSLATEID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id ChapterTranslateIDId = 0x69A5;

    class ChapterTranslateID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapterTranslateID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapterTranslateIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Info\\ChapterTranslate\\ChapterTranslateID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapterTranslateIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapterTranslateID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPTERTRANSLATEID_H
