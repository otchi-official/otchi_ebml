//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TITLE_H
#define INCLUDE_OTCHI_EBML_TITLE_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi {

    constexpr ebml_id TitleId = 0x7BA9;

    class Title : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Title";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TitleId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Info\\Title)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TitleFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new Title(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TITLE_H
