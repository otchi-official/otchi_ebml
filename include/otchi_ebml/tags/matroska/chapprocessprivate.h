//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHAPPROCESSPRIVATE_H
#define INCLUDE_OTCHI_EBML_CHAPPROCESSPRIVATE_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id ChapProcessPrivateId = 0x450D;

    class ChapProcessPrivate : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChapProcessPrivate";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ChapProcessPrivateId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Chapters\\EditionEntry\\ChapterAtom\\ChapProcess\\ChapProcessPrivate)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChapProcessPrivateFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ChapProcessPrivate(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHAPPROCESSPRIVATE_H
