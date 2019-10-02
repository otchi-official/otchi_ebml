//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FILEMIMETYPE_H
#define INCLUDE_OTCHI_EBML_FILEMIMETYPE_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id FileMimeTypeId = 0x4660;

    class FileMimeType : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FileMimeType";
        }

        [[nodiscard]] ebml_id getId() const override {
            return FileMimeTypeId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Attachments\\AttachedFile\\FileMimeType)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FileMimeTypeFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new FileMimeType(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FILEMIMETYPE_H
