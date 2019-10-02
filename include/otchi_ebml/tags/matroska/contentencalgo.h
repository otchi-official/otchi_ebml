//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CONTENTENCALGO_H
#define INCLUDE_OTCHI_EBML_CONTENTENCALGO_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id ContentEncAlgoId = 0x47E1;

    class ContentEncAlgo : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ContentEncAlgo";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ContentEncAlgoId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\ContentEncodings\\ContentEncoding\\ContentEncryption\\ContentEncAlgo)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ContentEncAlgoFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ContentEncAlgo(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CONTENTENCALGO_H
