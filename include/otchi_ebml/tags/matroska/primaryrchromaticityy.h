//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PRIMARYRCHROMATICITYY_H
#define INCLUDE_OTCHI_EBML_PRIMARYRCHROMATICITYY_H

#include "otchi_ebml/elements/ebml_element_double.h"

namespace otchi {

    constexpr ebml_id PrimaryRChromaticityYId = 0x55D2;

    class PrimaryRChromaticityY : public EBMLElement<EBMLType::kDouble> {
    public:
        using EBMLElement<EBMLType::kDouble>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PrimaryRChromaticityY";
        }

        [[nodiscard]] ebml_id getId() const override {
            return PrimaryRChromaticityYId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\MasteringMetadata\\PrimaryRChromaticityY)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PrimaryRChromaticityYFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new PrimaryRChromaticityY(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PRIMARYRCHROMATICITYY_H
