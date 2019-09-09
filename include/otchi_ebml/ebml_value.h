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
        long long size_;
    public:

        explicit EbmlValue(long long size): size_{size} {}

        virtual EbmlType getType() = 0;

        [[nodiscard]] long long getSize() const {
            return size_;
        }
    };

    class EbmlInt : public EbmlValue {
        int n_;
    public:
        explicit EbmlInt(long long size, int n) : EbmlValue{size}, n_{n} {}

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
        explicit EbmlUnsignedInt(long long size, unsigned int n) : EbmlValue{size}, n_{n} {}

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
        explicit EbmlDouble(long long size, double n) : EbmlValue{size}, n_{n} {}

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
        explicit EbmlString(long long size, std::string s) : EbmlValue{size}, s_{std::move(s)} {}

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
        explicit EbmlUtf8(long long size, std::string s): EbmlValue{size}, s_{std::move(s)} {}

        EbmlType getType() override {
            return EbmlType::kUTF8;
        }

        [[nodiscard]] std::string getValue() const {
            return s_;
        }
    };

    class EbmlDate: public EbmlValue{
        std::chrono::high_resolution_clock::time_point date_;
    public:
        explicit EbmlDate(long long size, std::chrono::high_resolution_clock::time_point n): EbmlValue{size}, date_{n} {}

        EbmlType getType() override {
            return EbmlType::kDate;
        }

        [[nodiscard]] std::chrono::high_resolution_clock::time_point getValue() const {
            return date_;
        }
    };

    class EbmlMaster: public EbmlValue {
        std::vector<EbmlValue*> children_;
    public:
        explicit EbmlMaster(long long size, std::vector<EbmlValue*> children): EbmlValue{size}, children_{std::move(children)} {}
        EbmlType getType() override {
            return EbmlType::kMaster;
        }

        void append(EbmlValue* child) {
            children_.push_back(child);
        }

        [[nodiscard]] std::vector<EbmlValue*> getChildren() const {
            return children_;
        }
    };

    class EbmlBinary: public EbmlValue {
        std::vector<char> buffer_;
    public:
        explicit EbmlBinary(long long size, std::vector<char> buffer): EbmlValue{size}, buffer_{std::move(buffer)} {}

        EbmlType getType() override {
            return EbmlType::kBinary;
        }

        [[nodiscard]] std::vector<char> getValue() const {
            return buffer_;
        }
    };



}


#endif //OTCHI_EBML_EBML_VALUE_H
