//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CODECINFOURL_H
#define INCLUDE_OTCHI_EBML_CODECINFOURL_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi_ebml {

    constexpr EBMLId CodecInfoURLId = 0x3B4040;

    class CodecInfoURL : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CodecInfoURL";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CodecInfoURLId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tracks\\TrackEntry\\CodecInfoURL)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CodecInfoURLFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CodecInfoURL(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CODECINFOURL_H
