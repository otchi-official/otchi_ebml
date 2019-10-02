//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEGMENTFAMILY_H
#define INCLUDE_OTCHI_EBML_SEGMENTFAMILY_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id SegmentFamilyId = 0x4444;

    class SegmentFamily : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SegmentFamily";
        }

        [[nodiscard]] ebml_id getId() const override {
            return SegmentFamilyId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Info\\SegmentFamily)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SegmentFamilyFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new SegmentFamily(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEGMENTFAMILY_H
