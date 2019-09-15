//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_DOCUMENT_H
#define INCLUDE_OTCHI_EBML_EBML_DOCUMENT_H

#include "ebml_element_master.h"

namespace otchi_ebml {
    struct EBMLDocument {
        EBMLElement<EBMLType::kMaster>* head_;
        EBMLElement<EBMLType::kMaster>* body;
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_DOCUMENT_H
