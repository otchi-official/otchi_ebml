//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TIMESLICE_H
#define INCLUDE_OTCHI_EBML_TIMESLICE_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id TimeSliceId = 0xE8;

    class TimeSlice : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TimeSlice";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TimeSliceId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Cluster\\BlockGroup\\Slices\\TimeSlice)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TimeSliceFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TimeSlice(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TIMESLICE_H
