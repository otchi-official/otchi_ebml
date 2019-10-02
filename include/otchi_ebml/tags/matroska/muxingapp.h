//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_MUXINGAPP_H
#define INCLUDE_OTCHI_EBML_MUXINGAPP_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi {

    constexpr ebml_id MuxingAppId = 0x4D80;

    class MuxingApp : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "MuxingApp";
        }

        [[nodiscard]] ebml_id getId() const override {
            return MuxingAppId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\Info\\MuxingApp)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class MuxingAppFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new MuxingApp(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_MUXINGAPP_H
