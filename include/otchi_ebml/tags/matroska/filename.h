//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FILENAME_H
#define INCLUDE_OTCHI_EBML_FILENAME_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi {

    constexpr ebml_id FileNameId = 0x466E;

    class FileName : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FileName";
        }

        [[nodiscard]] ebml_id getId() const override {
            return FileNameId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Attachments\\AttachedFile\\FileName)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FileNameFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new FileName(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FILENAME_H
