//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPTERTRANSLATECODEC_H
#define INCLUDE_OTCHI_EBML_CHAPTERTRANSLATECODEC_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id ChapterTranslateCodecId = 0x69BF;

    class ChapterTranslateCodec : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapterTranslateCodec";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapterTranslateCodecId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Info\\ChapterTranslate\\ChapterTranslateCodec)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapterTranslateCodecFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapterTranslateCodec(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPTERTRANSLATECODEC_H
