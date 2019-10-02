//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAGCHAPTERUID_H
#define INCLUDE_OTCHI_EBML_TAGCHAPTERUID_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id TagChapterUIDId = 0x63C4;

    class TagChapterUID : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TagChapterUID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TagChapterUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tags\\Tag\\Targets\\TagChapterUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagChapterUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TagChapterUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAGCHAPTERUID_H
