//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FILEUSEDENDTIME_H
#define INCLUDE_OTCHI_EBML_FILEUSEDENDTIME_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId FileUsedEndTimeId = 0x4662;

    class FileUsedEndTime : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FileUsedEndTime";
        }

        [[nodiscard]] EBMLId getId() const override {
            return FileUsedEndTimeId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Attachments\\AttachedFile\\FileUsedEndTime)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FileUsedEndTimeFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new FileUsedEndTime(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FILEUSEDENDTIME_H