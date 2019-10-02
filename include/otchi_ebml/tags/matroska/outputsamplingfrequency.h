//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_OUTPUTSAMPLINGFREQUENCY_H
#define INCLUDE_OTCHI_EBML_OUTPUTSAMPLINGFREQUENCY_H

#include "otchi_ebml/elements/ebml_element_double.h"

namespace otchi {

    constexpr ebml_id OutputSamplingFrequencyId = 0x78B5;

    class OutputSamplingFrequency : public EBMLElement<EBMLType::kDouble> {
    public:
        using EBMLElement<EBMLType::kDouble>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "OutputSamplingFrequency";
        }

        [[nodiscard]] ebml_id getId() const override {
            return OutputSamplingFrequencyId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Audio\\OutputSamplingFrequency)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class OutputSamplingFrequencyFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new OutputSamplingFrequency(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_OUTPUTSAMPLINGFREQUENCY_H
