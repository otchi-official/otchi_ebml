//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H

#include <iostream>
#include <vector>

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    template<>
    class EBMLElement<EBMLType::kMaster> : public EBMLBaseElement {
        std::vector<EBMLBaseElement *> children_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kMaster;
        }

        void decode(std::ifstream &ifstream) override {}


        [[nodiscard]] std::vector<EBMLBaseElement *> getChildren() const {
            return children_;
        }

        void append(EBMLBaseElement *element) {
            children_.push_back(element);
        }

        void print(int index) const {
            for (int i = 0; i < index; i++) {
                std::cout << "\t";
            }
            std::cout << std::dec << getName() << " [" << getPosition() << ", " << elementSize() << "]" << std::endl;
            for (EBMLBaseElement *child : children_) {
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
                if (dynamic_cast<EBMLElement<EBMLType::kMaster> *>(child)) {
                    dynamic_cast<EBMLElement<EBMLType::kMaster> *>(child)->print(index + 1);
                } else {
                    for (int i = 0; i < index + 1; i++) {
                        std::cout << "\t";
                    }
                    child->print();
                    std::cout << std::endl;
                }
#pragma clang diagnostic pop
            }
        }

        void print() const override {
            print(0);
        }


    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H
