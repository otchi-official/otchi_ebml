//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_TRACKTRANSLATETRACKID_H
#define INCLUDE_OTCHI_EBML_TRACKTRANSLATETRACKID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id TrackTranslateTrackIDId = 0x66A5;

    class TrackTranslateTrackID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "TrackTranslateTrackID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return TrackTranslateTrackIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\TrackTranslate\\TrackTranslateTrackID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class TrackTranslateTrackIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new TrackTranslateTrackID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_TRACKTRANSLATETRACKID_H
