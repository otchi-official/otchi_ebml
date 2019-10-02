//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SAMPLINGFREQUENCY_H
#define INCLUDE_OTCHI_EBML_SAMPLINGFREQUENCY_H

#include "otchi_ebml/elements/ebml_element_double.h"

namespace otchi {

    constexpr ebml_id SamplingFrequencyId = 0xB5;

    class SamplingFrequency : public EBMLElement<EBMLType::kDouble> {
    public:
        using EBMLElement<EBMLType::kDouble>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SamplingFrequency";
        }

        [[nodiscard]] ebml_id getId() const override {
            return SamplingFrequencyId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\Audio\\SamplingFrequency)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SamplingFrequencyFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new SamplingFrequency(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SAMPLINGFREQUENCY_H
