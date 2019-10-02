//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_DATE_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_DATE_H

#include <chrono>

#include "ebml_element.h"

namespace otchi::ebml {

    using ebml_clock = std::chrono::system_clock;

    template<>
    class EbmlElement<EbmlType::Date> : public AbstractEbmlElement {
        std::unique_ptr<ebml_clock::time_point> value_;

    public:

        using AbstractEbmlElement::AbstractEbmlElement;

        [[nodiscard]] EbmlType get_type() const override final;

        void decode(std::ifstream& ifstream) override;

        [[nodiscard]] ebml_clock::time_point get_value() const;
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_DATE_H
