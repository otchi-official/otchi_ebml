//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_H

// Abstract Base class for EBML Values

#include <string>
#include <unordered_map>

#include "ebml_type.h"
#include "otchi_ebml/ebml_constants.h"
#include "otchi_ebml/attributes/ebml_path.h"

namespace otchi_ebml {

    class EBMLBaseElement {

        int idSize_;
        int dataSize_;

    public:

        // Abstract methods
        [[nodiscard]] virtual EBMLType getType() = 0;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual EBMLId getId() const = 0;

        [[nodiscard]] virtual EBMLPath getPath() const = 0;

        // Virtual Methods

        [[nodiscard]] virtual int getMinOccurs() const { return 0; }

        [[nodiscard]] virtual int getMaxOccurs() const { return -1; }
        
    };

    template<const EBMLType type>
    class EBMLElement : EBMLBaseElement {

        EBMLType getType() override {
            return type;
        }
    };

    template<>
    class EBMLElement<EBMLType::kUInt> : EBMLBaseElement {
        unsigned int value;
    };


    /*template < const EBMLType type >
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

    };*/
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
