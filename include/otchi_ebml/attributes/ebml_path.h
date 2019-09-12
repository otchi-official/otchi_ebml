//
// Created by jorge on 9/12/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_PATH_H
#define INCLUDE_OTCHI_EBML_EBML_PATH_H

#include <string>
#include <utility>

namespace otchi_ebml {
    class EBMLPath {
        std::string path_;

    public:

        explicit EBMLPath(std::string path) : path_{std::move(path)} {}
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_PATH_H
