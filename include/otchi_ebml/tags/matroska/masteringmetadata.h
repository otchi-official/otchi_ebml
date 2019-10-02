//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_MASTERINGMETADATA_H
#define INCLUDE_OTCHI_EBML_MASTERINGMETADATA_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id MasteringMetadataId = 0x55D0;

    class MasteringMetadata : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "MasteringMetadata";
        }

        [[nodiscard]] ebml_id getId() const override {
            return MasteringMetadataId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\MasteringMetadata)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class MasteringMetadataFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new MasteringMetadata(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_MASTERINGMETADATA_H
