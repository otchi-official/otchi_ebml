//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CONTENTENCAESSETTINGS_H
#define INCLUDE_OTCHI_EBML_CONTENTENCAESSETTINGS_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi {

    constexpr ebml_id ContentEncAESSettingsId = 0x47E7;

    class ContentEncAESSettings : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ContentEncAESSettings";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ContentEncAESSettingsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\ContentEncodings\\ContentEncoding\\ContentEncryption\\ContentEncAESSettings)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ContentEncAESSettingsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ContentEncAESSettings(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CONTENTENCAESSETTINGS_H
