//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_NEXTFILENAME_H
#define INCLUDE_OTCHI_EBML_NEXTFILENAME_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi {

    constexpr ebml_id NextFilenameId = 0x3E83BB;

    class NextFilename : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "NextFilename";
        }

        [[nodiscard]] ebml_id getId() const override {
            return NextFilenameId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Info\\NextFilename)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class NextFilenameFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new NextFilename(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_NEXTFILENAME_H
