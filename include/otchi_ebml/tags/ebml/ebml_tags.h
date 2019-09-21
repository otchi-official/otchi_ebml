//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_TAGS_H
#define INCLUDE_OTCHI_EBML_EBML_TAGS_H

#include <unordered_map>

#include "otchi_ebml/elements/ebml_element_factory.h"


namespace otchi_ebml {

    class EBMLTags {
    public:
        static std::unordered_map<EBMLId, IEBMLElementFactory*> getEbmlHeadTags();
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_TAGS_H
