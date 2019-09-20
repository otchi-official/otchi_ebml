//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CUETRACKPOSITIONS_H
#define INCLUDE_OTCHI_EBML_CUETRACKPOSITIONS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId CueTrackPositionsId = 0xB7;

    class CueTrackPositions : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CueTrackPositions";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CueTrackPositionsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Cues\\CuePoint\\CueTrackPositions)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CueTrackPositionsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CueTrackPositions(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CUETRACKPOSITIONS_H
