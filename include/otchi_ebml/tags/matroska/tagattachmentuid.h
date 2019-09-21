//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAGATTACHMENTUID_H
#define INCLUDE_OTCHI_EBML_TAGATTACHMENTUID_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId TagAttachmentUIDId = 0x63C6;

    class TagAttachmentUID : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TagAttachmentUID";
        }

        [[nodiscard]] EBMLId getId() const override {
            return TagAttachmentUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tags\\Tag\\Targets\\TagAttachmentUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagAttachmentUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new TagAttachmentUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAGATTACHMENTUID_H
