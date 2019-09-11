//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_H

// Abstract Base class for EBML Values

#include <string>
#include <unordered_map>

#include "ebml_type.h"

namespace otchi_ebml {
    template < const EBMLType type >
    class EBMLElement {

        EBMLType type_ = type;

    public:

        [[nodiscard]] EBMLType getType() const {
            return type_;
        }

        // Abstract Getters

        // Factory Creator
        virtual EBMLElement* create() const = 0;

        [[nodiscard]] virtual std::string getName() const = 0;
        [[nodiscard]] virtual long long getId() const = 0;

        virtual bool validate() {return true;}
    };

    template<>
    class EBMLElement<EBMLType::kUInt> {
        using valueType = std::string;

    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
