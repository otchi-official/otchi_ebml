//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DOC_TYPE_VERSION_H
#define INCLUDE_OTCHI_EBML_DOC_TYPE_VERSION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DocTypeVersionId = 0x4287;

    class DocTypeVersion : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DocTypeVersion";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DocTypeVersionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\DocTypeVersion)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DocTypeVersionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DocTypeVersion(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DOC_TYPE_VERSION_H
