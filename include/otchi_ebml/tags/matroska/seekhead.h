//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEEKHEAD_H
#define INCLUDE_OTCHI_EBML_SEEKHEAD_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id SeekHeadId = 0x114D9B74;

    class SeekHead : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SeekHead";
        }

        [[nodiscard]] ebml_id getId() const override {
            return SeekHeadId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*2(\\Segment\\SeekHead)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SeekHeadFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new SeekHead(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEEKHEAD_H
