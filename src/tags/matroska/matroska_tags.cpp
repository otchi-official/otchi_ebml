//
// Created by paravicinij on 19.09.2019.
//

#include "otchi_ebml/tags/matroska/matroska_tags.h"

using namespace otchi_ebml;

std::unordered_map<EBMLId, IEBMLElementFactory *> otchi_ebml::MatroskaTags::getMatroskaTags() {
    static std::unordered_map<EBMLId, IEBMLElementFactory *> tags
    {

    };
    return tags;
}

