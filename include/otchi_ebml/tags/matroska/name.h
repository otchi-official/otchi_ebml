//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_NAME_H
#define INCLUDE_OTCHI_EBML_NAME_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi_ebml {

    constexpr EBMLId NameId = 0x536E;

    class Name : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Name";
        }

        [[nodiscard]] EBMLId getId() const override {
            return NameId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Name)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class NameFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Name(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_NAME_H
