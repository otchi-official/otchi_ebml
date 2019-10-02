//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TARGETTYPE_H
#define INCLUDE_OTCHI_EBML_TARGETTYPE_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id TargetTypeId = 0x63CA;

    class TargetType : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TargetType";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TargetTypeId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tags\\Tag\\Targets\\TargetType)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TargetTypeFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TargetType(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TARGETTYPE_H
