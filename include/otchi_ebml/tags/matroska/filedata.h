//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FILEDATA_H
#define INCLUDE_OTCHI_EBML_FILEDATA_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId FileDataId = 0x465C;

    class FileData : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FileData";
        }

        [[nodiscard]] EBMLId getId() const override {
            return FileDataId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Attachments\\AttachedFile\\FileData)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FileDataFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new FileData(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FILEDATA_H
