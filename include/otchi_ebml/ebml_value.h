//
// Created by jorge on 9/3/2019.
//

#ifndef OTCHI_EBML_EBML_VALUE_H
#define OTCHI_EBML_EBML_VALUE_H

#include <type_traits>
#include <string>
#include <utility>
#include <vector>
#include <ctime>

namespace otchi_ebml {

    /*
     * enum class EbmlType {
        kSInt,
        kUInt,
        kDouble,
        kString,
        kUTF8,
        kDate,
        kMaster,
        kBinary
    };

    class EBMLElement {
        long long contentSize_;
        long long size_;
        long long start_;
    public:

        explicit EBMLElement(long long start, long long contentSize, long long size) :
                start_{start},
                contentSize_{contentSize},
                size_{size} {}

        virtual EbmlType getType() = 0;

        [[nodiscard]] long long getContentSize() const {
            return contentSize_;
        }

        [[nodiscard]] long long getSize() const {
            return size_;
        }

        [[nodiscard]] long long getStart() const {
            return start_;
        }
    };

    class EbmlInt : public EBMLElement {
        int n_;
    public:
        explicit EbmlInt(long long start, long long contentSize, long long size, int n) :
                EBMLElement{start, contentSize, size}, n_{n} {}

        EbmlType getType() override {
            return EbmlType::kSInt;
        }

        [[nodiscard]] int getValue() const {
            return n_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlInt &i) {
        return os << "EBML Int: " << i.getValue() << "\n";
    }

    class EbmlUnsignedInt : public EBMLElement {
        unsigned int n_;
    public:
        explicit EbmlUnsignedInt(long long start, long long contentSize, long long size, unsigned int n) :
                EBMLElement{start, contentSize, size}, n_{n} {}

        EbmlType getType() override {
            return EbmlType::kUInt;
        }

        [[nodiscard]] unsigned int getValue() const {
            return n_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlUnsignedInt &uint) {
        return os << "EBML Unsigned Int: " << uint.getValue() << "\n";
    }

    class EbmlDouble : public EBMLElement {
        double n_;
    public:
        explicit EbmlDouble(long long start, long long contentSize, long long size, double n) :
                EBMLElement{start, contentSize, size}, n_{n} {}

        EbmlType getType() override {
            return EbmlType::kDouble;
        }

        [[nodiscard]] double getValue() const {
            return n_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlDouble &d) {
        return os << "EBML Double: " << d.getValue() << "\n";
    }

    class EbmlString : public EBMLElement {
        std::string s_;
    public:
        explicit EbmlString(long long start, long long contentSize, long long size, std::string s) :
                EBMLElement{start, contentSize, size}, s_{std::move(s)} {}

        EbmlType getType() override {
            return EbmlType::kString;
        }

        [[nodiscard]] std::string getValue() const {
            return s_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlString &s) {
        return os << "EBML String: " << s.getValue() << "\n";
    }

    class EbmlUtf8 : public EBMLElement {
        std::string s_;
    public:
        explicit EbmlUtf8(long long start, long long contentSize, long long size, std::string s) :
                EBMLElement{start, contentSize, size}, s_{std::move(s)} {}

        EbmlType getType() override {
            return EbmlType::kUTF8;
        }

        [[nodiscard]] std::string getValue() const {
            return s_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlUtf8 &s) {
        return os << "EBML UTF8: " << s.getValue() << "\n";
    }

    class EbmlDate : public EBMLElement {
        std::chrono::system_clock::time_point date_;
    public:
        explicit EbmlDate(long long start, long long contentSize, long long size,
                          std::chrono::system_clock::time_point n) :
                EBMLElement{start, contentSize, size}, date_{n} {}

        EbmlType getType() override {
            return EbmlType::kDate;
        }

        [[nodiscard]] std::chrono::system_clock::time_point getValue() const {
            return date_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlDate &date) {
        auto time = std::chrono::system_clock::to_time_t(date.getValue());
        return os << "EBML Date: " << ctime(&time) << "\n";
    }

    class EbmlBinary : public EBMLElement {
        std::vector<char> buffer_;
    public:
        explicit EbmlBinary(long long start, long long contentSize, long long size, std::vector<char> buffer) :
                EBMLElement{start, contentSize, size}, buffer_{std::move(buffer)} {}

        EbmlType getType() override {
            return EbmlType::kBinary;
        }

        [[nodiscard]] std::vector<char> getValue() const {
            return buffer_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlBinary &_) {
        return os << "EBML Binary\n";
    }

    class EbmlMaster : public EBMLElement {
        std::vector<EBMLElement *> children_;
    public:
        explicit EbmlMaster(long long start, long long contentSize, long long size, std::vector<EBMLElement *> children) :
                EBMLElement{start, contentSize, size}, children_{std::move(children)} {}

        EbmlType getType() override {
            return EbmlType::kMaster;
        }

        void append(EBMLElement *child) {
            children_.push_back(child);
        }

        [[nodiscard]] std::vector<EBMLElement *> getChildren() const {
            return children_;
        }
    };

    std::ostream &operator<<(std::ostream &os, const EbmlMaster &master) {
        os << "EBML Master:\n";
        for (auto child : master.getChildren()) {
            os << "\t";
            switch (child->getType()) {
                case EbmlType::kUInt:
                    os << dynamic_cast<EbmlUnsignedInt &>(*child);
                    break;
                case EbmlType::kMaster:
                    os << dynamic_cast<EbmlMaster &>(*child);
                    break;
                case EbmlType::kDate:
                    os << dynamic_cast<EbmlDate &>(*child);
                    break;
                case EbmlType::kBinary:
                    os << dynamic_cast<EbmlBinary &>(*child);
                    break;
                case EbmlType::kUTF8:
                    os << dynamic_cast<EbmlUtf8 &>(*child);
                    break;
                case EbmlType::kString:
                    os << dynamic_cast<EbmlString &>(*child);
                    break;
                case EbmlType::kDouble:
                    os << dynamic_cast<EbmlDouble &>(*child);
                    break;
                case EbmlType::kSInt:
                    os << dynamic_cast<EbmlInt &>(*child);
                    break;
            }
        }
        return os;
    }*/


}


#endif //OTCHI_EBML_EBML_VALUE_H
