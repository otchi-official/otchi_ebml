//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_DOCUMENT_H
#define INCLUDE_OTCHI_EBML_EBML_DOCUMENT_H

#include "ebml_element_master.h"
#include "otchi_ebml/tags/ebml/ebml_head.h"

namespace otchi::ebml {
    struct EbmlDocument {
        std::unique_ptr<EBMLHead> head;
        std::unique_ptr<EbmlElement<EbmlType::Master>> body;
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_DOCUMENT_H
