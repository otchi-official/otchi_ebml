//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_ATTACHEDFILE_H
#define INCLUDE_OTCHI_EBML_ATTACHEDFILE_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId AttachedFileId = 0x61A7;

    class AttachedFile : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "AttachedFile";
        }

        [[nodiscard]] EBMLId getId() const override {
            return AttachedFileId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Attachments\\AttachedFile)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class AttachedFileFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new AttachedFile(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_ATTACHEDFILE_H
