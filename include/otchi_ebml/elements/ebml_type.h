//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_TYPE_H
#define INCLUDE_OTCHI_EBML_EBML_TYPE_H

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
}

#endif //INCLUDE_OTCHI_EBML_EBML_TYPE_H
