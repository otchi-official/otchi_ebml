//
// Created by jorge on 9/10/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_PARSER_H
#define INCLUDE_OTCHI_EBML_EBML_PARSER_H

#include <unordered_map>
#include <functional>

#include "otchi_ebml/ebml_constants.h"
#include "ebml_element.h"

namespace otchi_ebml {
    class EBMLParser {

        std::unordered_map<EBMLId, std::function<*EBMLElement,

    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_PARSER_H
