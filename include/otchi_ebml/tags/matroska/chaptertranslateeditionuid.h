//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPTERTRANSLATEEDITIONUID_H
#define INCLUDE_OTCHI_EBML_CHAPTERTRANSLATEEDITIONUID_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId ChapterTranslateEditionUIDId = 0x69FC;

    class ChapterTranslateEditionUID : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapterTranslateEditionUID";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ChapterTranslateEditionUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Info\\ChapterTranslate\\ChapterTranslateEditionUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapterTranslateEditionUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ChapterTranslateEditionUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPTERTRANSLATEEDITIONUID_H
