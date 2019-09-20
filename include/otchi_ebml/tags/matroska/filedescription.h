//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FILEDESCRIPTION_H
#define INCLUDE_OTCHI_EBML_FILEDESCRIPTION_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi_ebml {

    constexpr EBMLId FileDescriptionId = 0x467E;

    class FileDescription : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FileDescription";
        }

        [[nodiscard]] EBMLId getId() const override {
            return FileDescriptionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Attachments\\AttachedFile\\FileDescription)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FileDescriptionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new FileDescription(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FILEDESCRIPTION_H
