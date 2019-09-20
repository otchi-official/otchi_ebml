//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CONTENTSIGNATURE_H
#define INCLUDE_OTCHI_EBML_CONTENTSIGNATURE_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId ContentSignatureId = 0x47E3;

    class ContentSignature : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ContentSignature";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ContentSignatureId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\ContentEncodings\\ContentEncoding\\ContentEncryption\\ContentSignature)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ContentSignatureFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ContentSignature(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CONTENTSIGNATURE_H
