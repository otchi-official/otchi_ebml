//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PRIMARYGCHROMATICITYY_H
#define INCLUDE_OTCHI_EBML_PRIMARYGCHROMATICITYY_H

#include "otchi_ebml/elements/ebml_element_double.h"

namespace otchi {

    constexpr ebml_id PrimaryGChromaticityYId = 0x55D4;

    class PrimaryGChromaticityY : public EBMLElement<EBMLType::kDouble> {
    public:
        using EBMLElement<EBMLType::kDouble>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PrimaryGChromaticityY";
        }

        [[nodiscard]] ebml_id getId() const override {
            return PrimaryGChromaticityYId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\MasteringMetadata\\PrimaryGChromaticityY)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PrimaryGChromaticityYFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new PrimaryGChromaticityY(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PRIMARYGCHROMATICITYY_H
