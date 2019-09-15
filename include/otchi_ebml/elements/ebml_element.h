//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_H

// Abstract Base class for EBML Values

#include <string>
#include <unordered_map>
#include <optional>
#include <utility>
#include <fstream>

#include "ebml_type.h"
#include "otchi_ebml/types/ebml_alias.h"
#include "otchi_ebml/attributes/ebml_path.h"

namespace otchi_ebml {

    class EBMLBaseElement {

        EBMLIdSize idSize_;
        EBMLDataSize dataSize_;
        EBMLContentSize contentSize_;

    public:

        EBMLBaseElement(EBMLIdSize idSize, EBMLDataSize dataSize, EBMLContentSize dataContentSize) :
                idSize_{idSize}, dataSize_{dataSize}, contentSize_{dataContentSize} {}

        // Abstract methods
        [[nodiscard]] virtual EBMLType getType() = 0;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual EBMLId getId() const = 0;

        // Virtual Methods

        [[nodiscard]] virtual bool isMandatory() const { return false; }

        [[nodiscard]] virtual bool validateRange() const { return true; }

        [[nodiscard]] virtual bool multipleAllowed() const { return false; }

        [[nodiscard]] virtual std::string getDescription() const { return ""; }

        // TODO ENCODE

        virtual void decode(std::ifstream ifstream) = 0;

        // getters
        [[nodiscard]] EBMLIdSize getIdSize() const { return idSize_; }

        [[nodiscard]] EBMLDataSize getDataSize() const { return dataSize_; }

        [[nodiscard]] EBMLContentSize getContentSize() const { return contentSize_; }

    };

    template<const EBMLType type>
    class EBMLElement : EBMLBaseElement {
        using EBMLBaseElement::EBMLBaseElement;
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
