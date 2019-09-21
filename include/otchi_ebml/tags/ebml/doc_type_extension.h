//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_H
#define INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId DocTypeExtensionId = 0x4281;

    class DocTypeExtension : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DocTypeExtension";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DocTypeExtensionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\EBML\\DocTypeExtension)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "A DocTypeExtension adds extra Elements to the main DocType+DocTypeVersion tuple it's attached to. An EBML Reader MAY know these extra Elements and how to use them. A DocTypeExtension MAY be used to iterate between experimental Elements before they are integrated in a regular DocTypeVersion. Reading one DocTypeExtension version of a DocType+DocTypeVersion tuple doesn't imply one should be able to read upper versions of this DocTypeExtension.";
        }
    };

    class DocTypeExtensionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DocTypeExtension(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DOC_TYPE_EXTENSION_H
