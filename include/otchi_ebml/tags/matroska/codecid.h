//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CODECID_H
#define INCLUDE_OTCHI_EBML_CODECID_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id CodecIDId = 0x86;

    class CodecID : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CodecID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return CodecIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Tracks\\TrackEntry\\CodecID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CodecIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new CodecID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CODECID_H
