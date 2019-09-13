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

#include "ebml_type.h"
#include "otchi_ebml/ebml_constants.h"
#include "otchi_ebml/attributes/ebml_path.h"
#include "ebml_scheme.h"

namespace otchi_ebml {

    class EBMLBaseElement {

        EBMLIdSize idSize_;
        EBMLDataSize dataSize_;
        EBMLScheme scheme_;

    public:

        // Abstract methods
        [[nodiscard]] virtual EBMLType getType() = 0;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual EBMLId getId() const = 0;

        [[nodiscard]] virtual EBMLPath getPath() const = 0;

        // Virtual Methods

        [[nodiscard]] virtual int getMinOccurs() const { return 0; }

        [[nodiscard]] virtual std::optional<int> getMaxOccurs() const { return std::nullopt; }

        [[nodiscard]] virtual std::optional<std::tuple<EBMLDataSize, EBMLDataSize>>
        getDataLengthRange() const { return std::nullopt; }

        // ONLY MASTER
        // TODO: Maybe move to master implementation
        [[nodiscard]] virtual bool getUnknownSizeAllowed() const { return false; }

        // ONLY MASTER
        // TODO: Maybe move to master implementation
        // TODO: Maybe don't make it virtual if it can be inferred
        // TODO: Can be inferred from path see second paragraph:
        // https://github.com/cellar-wg/ebml-specification/blob/master/specification.markdown#recursive
        [[nodiscard]] virtual bool getRecursive() const { return false; }

        [[nodiscard]] virtual bool getRecurring() const { return false; }

        [[nodiscard]] virtual unsigned int getMinVer() const { return false; }

        [[nodiscard]] virtual unsigned int getMaxVer() const { return scheme_.getVersion(); }

        [[nodiscard]] virtual std::string getDescription() const { return ""; }


        // TODO METHODS: RANGE, DEFAULT

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
