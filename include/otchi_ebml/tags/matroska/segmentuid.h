//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEGMENTUID_H
#define INCLUDE_OTCHI_EBML_SEGMENTUID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId SegmentUIDId = 0x73A4;

    class SegmentUID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SegmentUID";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SegmentUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Info\\SegmentUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SegmentUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new SegmentUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEGMENTUID_H
