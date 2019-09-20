//
// Created by Jorge Paravicini on 2019-09-19
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DOC_TYPE_READ_VERSION_H
#define INCLUDE_OTCHI_EBML_DOC_TYPE_READ_VERSION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId DocTypeReadVersionId = 0x4285;

    class DocTypeReadVersion : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DocTypeReadVersion";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DocTypeReadVersionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\DocTypeReadVersion)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "The minimum DocType version an EBML Reader has to support to read this EBML Document. The value of the DocTypeReadVersion Element MUST be less than or equal to the value of the DocTypeVersion Element.";
        }
    };

    class DocTypeReadVersionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DocTypeReadVersion(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DOC_TYPE_READ_VERSION_H
