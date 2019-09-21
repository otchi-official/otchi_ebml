//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_DOC_TYPE_H
#define INCLUDE_OTCHI_EBML_EBML_DOC_TYPE_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi_ebml {

    constexpr EBMLId EBMLDocTypeId = 0x4282;

    class EBMLDocType : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DocType";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EBMLDocTypeId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\DocType)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "A string that describes and identifies the content of the EBML Body that follows this EBML Header.";
        }
    };

    class EBMLDocTypeFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new EBMLDocType(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_DOC_TYPE_H
