//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PREVFILENAME_H
#define INCLUDE_OTCHI_EBML_PREVFILENAME_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi_ebml {

    constexpr EBMLId PrevFilenameId = 0x3C83AB;

    class PrevFilename : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PrevFilename";
        }

        [[nodiscard]] EBMLId getId() const override {
            return PrevFilenameId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Info\\PrevFilename)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PrevFilenameFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new PrevFilename(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PREVFILENAME_H
