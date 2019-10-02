//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKTRANSLATE_H
#define INCLUDE_OTCHI_EBML_TRACKTRANSLATE_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id TrackTranslateId = 0x6624;

    class TrackTranslate : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackTranslate";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TrackTranslateId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tracks\\TrackEntry\\TrackTranslate)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackTranslateFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TrackTranslate(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKTRANSLATE_H
