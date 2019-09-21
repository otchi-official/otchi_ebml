//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_VERSION_H
#define INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_VERSION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DocTypeExtensionVersionId = 0x4284;

    class DocTypeExtensionVersion : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DocTypeExtensionVersion";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DocTypeExtensionVersionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\DocTypeExtension\\Version)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return " ";
        }
    };

    class DocTypeExtensionVersionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DocTypeExtensionVersion(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_VERSION_H
