//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CUEREFCLUSTER_H
#define INCLUDE_OTCHI_EBML_CUEREFCLUSTER_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId CueRefClusterId = 0x97;

    class CueRefCluster : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CueRefCluster";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CueRefClusterId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Cues\\CuePoint\\CueTrackPositions\\CueReference\\CueRefCluster)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CueRefClusterFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CueRefCluster(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CUEREFCLUSTER_H
