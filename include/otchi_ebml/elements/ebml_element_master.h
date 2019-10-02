//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H

#include <vector>
#include <memory>

#include "ebml_element.h"

namespace otchi::ebml {

    template<>
    class EbmlElement<EbmlType::Master> : public AbstractEbmlElement {
        std::vector<std::shared_ptr<AbstractEbmlElement>> children_;

    public:

        using AbstractEbmlElement::AbstractEbmlElement;

        [[nodiscard]] EbmlType get_type() const override final;

        void decode(std::ifstream &ifstream) override {}


        [[nodiscard]] std::vector<std::shared_ptr<AbstractEbmlElement>> get_children() const;

        void append(const std::shared_ptr<AbstractEbmlElement>& element);

        void print(int index) const;

        void print() const override;
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_MASTER_H
