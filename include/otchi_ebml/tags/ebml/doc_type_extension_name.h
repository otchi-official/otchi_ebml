//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_NAME_H
#define INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_NAME_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi_ebml {

    constexpr EBMLId DocTypeExtensionNameId = 0x4283;

    class DocTypeExtensionName : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DocTypeExtensionName";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DocTypeExtensionNameId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\DocTypeExtension\\Name)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "The name of the DocTypeExtension to differentiate it from other DocTypeExtension of the same DocType+DocTypeVersion tuple. A DocTypeExtensionName value MUST be unique within the EBML Header.";
        }
    };

    class DocTypeExtensionNameFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DocTypeExtensionName(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_NAME_H
