//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CODECDOWNLOADURL_H
#define INCLUDE_OTCHI_EBML_CODECDOWNLOADURL_H

#include "otchi_ebml/elements/ebml_element_string.h"

namespace otchi {

    constexpr ebml_id CodecDownloadURLId = 0x26B240;

    class CodecDownloadURL : public EBMLElement<EBMLType::kString> {
    public:
        using EBMLElement<EBMLType::kString>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CodecDownloadURL";
        }

        [[nodiscard]] ebml_id getId() const override {
            return CodecDownloadURLId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Tracks\\TrackEntry\\CodecDownloadURL)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CodecDownloadURLFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new CodecDownloadURL(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CODECDOWNLOADURL_H
