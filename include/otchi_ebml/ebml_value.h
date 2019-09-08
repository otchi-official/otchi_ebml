//
// Created by jorge on 9/3/2019.
//

#ifndef OTCHI_EBML_EBML_VALUE_H
#define OTCHI_EBML_EBML_VALUE_H

#include <type_traits>
#include <string>
#include <utility>
#include <vector>

namespace otchi_ebml {

    enum class EbmlType {
        kSInt,
        kUInt,
        kDouble,
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

    class EbmlInt : public EbmlValue {
        int n_;
    public:
        explicit EbmlInt(int n) : n_{n} {}

        EbmlType getType() override {
            return EbmlType::kSInt;
        }

        [[nodiscard]] int getValue() const {
            return n_;
        }
    };

    class EbmlUnsignedInt : public EbmlValue {
        unsigned int n_;
    public:
        explicit EbmlUnsignedInt(unsigned int n) : n_{n} {}

        EbmlType getType() override {
            return EbmlType::kUInt;
        }

        [[nodiscard]] unsigned int getValue() const {
            return n_;
        }
    };

    class EbmlDouble : public EbmlValue {
        double n_;
    public:
        explicit EbmlDouble(double n) : n_{n} {}

        EbmlType getType() override {
            return EbmlType::kDouble;
        }

        [[nodiscard]] double getValue() const {
            return n_;
        }
    };

    class EbmlString : public EbmlValue {
        std::string s_;
    public:
        explicit EbmlString(std::string s) : s_{std::move(s)} {}

        EbmlType getType() override {
            return EbmlType::kString;
        }

        [[nodiscard]] std::string getValue() const {
            return s_;
        }
    };

    class EbmlUtf8: public EbmlValue {
        std::string s_;
    public:
        explicit EbmlUtf8(std::string s): s_{std::move(s)} {}

        EbmlType getType() override {
            return EbmlType::kUTF8;
        }

        [[nodiscard]] std::string getValue() const {
            return s_;
        }
    };

    class EbmlDate: public EbmlValue{
        int date_;
    public:
        explicit EbmlDate(int n): date_{n} {}

        EbmlType getType() override {
            return EbmlType::kDate;
        }

        [[nodiscard]] int getValue() const {
            return date_;
        }
    };

    class EbmlMaster: public EbmlValue {
        EbmlType getType() override {
            return EbmlType::kMaster;
        }
    };

    class EbmlBinary: public EbmlValue {
        std::vector<char> buffer_;
    public:
        explicit EbmlBinary(std::vector<char> buffer): buffer_{std::move(buffer)} {}

        EbmlType getType() override {
            return EbmlType::kBinary;
        }

        [[nodiscard]] std::vector<char> getValue() const {
            return buffer_;
        }
    };



}


#endif //OTCHI_EBML_EBML_VALUE_H
