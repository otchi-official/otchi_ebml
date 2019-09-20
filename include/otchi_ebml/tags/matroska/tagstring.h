//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAGSTRING_H
#define INCLUDE_OTCHI_EBML_TAGSTRING_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi_ebml {

    constexpr EBMLId TagStringId = 0x4487;

    class TagString : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TagString";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TagStringId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tags\\Tag\\SimpleTag\\TagString)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagStringFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new TagString(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAGSTRING_H
