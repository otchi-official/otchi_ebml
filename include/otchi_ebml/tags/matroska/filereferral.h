//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_FILEREFERRAL_H
#define INCLUDE_OTCHI_EBML_FILEREFERRAL_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId FileReferralId = 0x4675;

    class FileReferral : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "FileReferral";
        }

        [[nodiscard]] EBMLId getId() const override {
            return FileReferralId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Attachments\\AttachedFile\\FileReferral)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class FileReferralFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new FileReferral(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_FILEREFERRAL_H
