//
// Created by jorge on 9/13/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_SCHEME_H
#define INCLUDE_OTCHI_EBML_EBML_SCHEME_H

#include <string>

namespace otchi_ebml {
    class EBMLScheme {
        std::string docType_;
        unsigned int version_;

    public:
        EBMLScheme(std::string docType, unsigned int version) : docType_{std::move(docType)}, version_{version} {}

        [[nodiscard]] std::string getDocType() const { return docType_; }

        [[nodiscard]] unsigned int getVersion() const { return version_; }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_SCHEME_H
