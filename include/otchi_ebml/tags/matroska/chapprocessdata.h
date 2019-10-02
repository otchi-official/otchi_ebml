//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPPROCESSDATA_H
#define INCLUDE_OTCHI_EBML_CHAPPROCESSDATA_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id ChapProcessDataId = 0x6933;

    class ChapProcessData : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapProcessData";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapProcessDataId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapProcess\\ChapProcessCommand\\ChapProcessData)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapProcessDataFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapProcessData(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPPROCESSDATA_H
