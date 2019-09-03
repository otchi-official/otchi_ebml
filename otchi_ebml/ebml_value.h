//
// Created by jorge on 9/3/2019.
//

#ifndef OTCHI_EBML_EBML_VALUE_H
#define OTCHI_EBML_EBML_VALUE_H

#include <type_traits>
#include <string>
#include <utility>

namespace otchi_ebml {

    enum class EbmlType {
        kSInt,
        kUInt,
        kFloat,
        kString,
        kUTF8,
        kDate,
        kMaster,
        kBinary
    };

    class EbmlValue {
    public:
        virtual EbmlType getType() = 0;
    };

    class EbmlInt : EbmlValue {
        int n_;
    public:
        explicit EbmlInt(int n) : n_{n} {}

        EbmlType getType() override {
            return EbmlType::kSInt;
        }

        int getValue() const {
            return n_;
        }
    };

    class EbmlUnsignedInt : EbmlValue {
        unsigned int n_;
    public:
        explicit EbmlUnsignedInt(unsigned int n) : n_{n} {}

        EbmlType getType() override {
            return EbmlType::kUInt;
        }

        unsigned int getValue() const {
            return n_;
        }
    };

    class EbmlFloat : EbmlValue {
        float n_;
    public:
        explicit EbmlFloat(float n) : n_{n} {}

        EbmlType getType() override {
            return EbmlType::kFloat;
        }

        float getValue() const {
            return n_;
        }
    };

    class EbmlString : EbmlValue {
        std::string s_;
    public:
        explicit EbmlString(std::string s) : s_{std::move(s)} {}

        EbmlType getType() override {
            return EbmlType::kString;
        }

        std::string getValue() const {
            return s_;
        }
    };

}


#endif //OTCHI_EBML_EBML_VALUE_H
