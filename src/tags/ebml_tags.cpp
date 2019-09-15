//
// Created by jorge on 9/15/2019.
//

#include "otchi_ebml/tags/ebml_tags.h"

#include "otchi_ebml/tags/ebml_head.h"

using namespace otchi_ebml;

std::unordered_map<EBMLId, IEBMLElementFactory *> EBMLTags::getEbmlHeadTags() {
    static std::unordered_map<EBMLId, IEBMLElementFactory *> tags{
            {EBMLHeadID, new EBMLHeadFactory()}
    };
    return tags;
}