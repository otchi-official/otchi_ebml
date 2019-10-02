//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CONTENTSIGALGO_H
#define INCLUDE_OTCHI_EBML_CONTENTSIGALGO_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id ContentSigAlgoId = 0x47E5;

    class ContentSigAlgo : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ContentSigAlgo";
        }

        [[nodiscard]] ebml_id getId() const override {
            return ContentSigAlgoId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\ContentEncodings\\ContentEncoding\\ContentEncryption\\ContentSigAlgo)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ContentSigAlgoFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new ContentSigAlgo(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CONTENTSIGALGO_H
