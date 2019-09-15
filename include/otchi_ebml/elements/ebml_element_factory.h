//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_FACTORY_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_FACTORY_H

#include "ebml_element.h"
#include "otchi_ebml/types/ebml_alias.h"

namespace otchi_ebml {

    class IEBMLElementFactory {
    public:
        virtual EBMLBaseElement *create(
                EBMLSize idSize,
                EBMLSize dataSize,
                EBMLSize dataContentSize,
                EBMLPosition position) = 0;
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_FACTORY_H
