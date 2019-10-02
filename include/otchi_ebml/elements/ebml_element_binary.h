//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_BINARY_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_BINARY_H

#include <vector>

#include "ebml_element.h"

namespace otchi::ebml {

    template<>
    class EbmlElement<EbmlType::Binary> : public AbstractEbmlElement {
    	std::unique_ptr<std::vector<char>> value_;

    public:

		using AbstractEbmlElement::AbstractEbmlElement;

        [[nodiscard]] EbmlType get_type() const override final;

        void decode(std::ifstream& ifstream) override;

        [[nodiscard]] const std::vector<char>& get_value() const;

        void print() const override;
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_BINARY_H
