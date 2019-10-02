//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CONTENTENCODINGTYPE_H
#define INCLUDE_OTCHI_EBML_CONTENTENCODINGTYPE_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id ContentEncodingTypeId = 0x5033;

    class ContentEncodingType : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ContentEncodingType";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ContentEncodingTypeId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\ContentEncodings\\ContentEncoding\\ContentEncodingType)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ContentEncodingTypeFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ContentEncodingType(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CONTENTENCODINGTYPE_H
