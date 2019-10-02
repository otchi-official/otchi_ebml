//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SILENTTRACKS_H
#define INCLUDE_OTCHI_EBML_SILENTTRACKS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id SilentTracksId = 0x5854;

    class SilentTracks : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SilentTracks";
        }

        [[nodiscard]] ebml_id getId() const override {
            return SilentTracksId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Cluster\\SilentTracks)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SilentTracksFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new SilentTracks(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SILENTTRACKS_H
