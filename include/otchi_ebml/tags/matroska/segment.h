//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEGMENT_H
#define INCLUDE_OTCHI_EBML_SEGMENT_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId SegmentId = 0x18538067;

    class Segment : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Segment";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SegmentId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SegmentFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Segment(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEGMENT_H
