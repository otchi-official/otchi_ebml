//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CODECDECODEALL_H
#define INCLUDE_OTCHI_EBML_CODECDECODEALL_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi {

    constexpr ebml_id CodecDecodeAllId = 0xAA;

    class CodecDecodeAll : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CodecDecodeAll";
        }

        [[nodiscard]] ebml_id getId() const override {
            return CodecDecodeAllId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\CodecDecodeAll)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CodecDecodeAllFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new CodecDecodeAll(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CODECDECODEALL_H
