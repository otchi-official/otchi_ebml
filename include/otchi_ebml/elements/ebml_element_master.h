//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    template<>
    class EBMLElement<EBMLType::kMaster> : public EBMLBaseElement {
        std::vector<EBMLBaseElement*> children_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kString;
        }

        void decode(std::ifstream &ifstream) override {}


        [[nodiscard]] std::vector<EBMLBaseElement*> getChildren() const {
            return children_;
        }

        void append(EBMLBaseElement* element) {
            children_.push_back(element);
        }
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H
