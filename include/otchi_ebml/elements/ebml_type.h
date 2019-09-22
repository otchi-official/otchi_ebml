//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_TYPE_H
#define INCLUDE_OTCHI_EBML_EBML_TYPE_H

#include <iostream>

namespace otchi_ebml {
    enum class EBMLType {
        kSInt,
        kUInt,
        kDouble,
        kString,
        kUTF8,
        kDate,
        kMaster,
        kBinary
    };

    namespace {
        std::ostream &operator<<(std::ostream &os, const EBMLType &type) {
            switch (type) {
                case EBMLType::kSInt:
                    os << "Signed Integer";
                    break;
                case EBMLType::kUInt:
                    os << "Unsigned Integer";
                    break;
                case EBMLType::kDouble:
                    os << "Double";
                    break;
                case EBMLType::kString:
                    os << "String";
                    break;
                case EBMLType::kUTF8:
                    os << "UTF 8";
                    break;
                case EBMLType::kDate:
                    os << "Date";
                    break;
                case EBMLType::kMaster:
                    os << "Master";
                    break;
                case EBMLType::kBinary:
                    os << "Binary";
                    break;
            }
            return os;
        }
    }
}

#endif //INCLUDE_OTCHI_EBML_EBML_TYPE_H
