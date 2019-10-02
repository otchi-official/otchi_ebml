//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_TYPE_H
#define INCLUDE_OTCHI_EBML_EBML_TYPE_H
#include <ostream>

namespace otchi::ebml {
    enum class EbmlType {
        SignedInteger,
        UnsignedInteger,
        Double,
        String,
        Utf8,
        Date,
        Master,
        Binary
    };

	std::ostream& operator<<(std::ostream& os, const EbmlType& type);
}

#endif //INCLUDE_OTCHI_EBML_EBML_TYPE_H
