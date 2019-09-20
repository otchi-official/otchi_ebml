//
// Created by paravicinij on 19.09.2019.
//

#ifndef INCLUDE_OTCHI_EBML_MATROSKA_TAGS_H
#define INCLUDE_OTCHI_EBML_MATROSKA_TAGS_H

#include <unordered_map>

#include "otchi_ebml/elements/ebml_element_factory.h"

namespace otchi_ebml {
    class MatroskaTags {
    public:
        static std::unordered_map<EBMLId, IEBMLElementFactory*> getMatroskaTags();
    };
}

#endif //INCLUDE_OTCHI_EBML_MATROSKA_TAGS_H
