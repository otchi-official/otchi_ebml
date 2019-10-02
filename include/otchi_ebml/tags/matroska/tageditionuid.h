//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TAGEDITIONUID_H
#define INCLUDE_OTCHI_EBML_TAGEDITIONUID_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id TagEditionUIDId = 0x63C9;

    class TagEditionUID : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TagEditionUID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TagEditionUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tags\\Tag\\Targets\\TagEditionUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TagEditionUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TagEditionUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TAGEDITIONUID_H
