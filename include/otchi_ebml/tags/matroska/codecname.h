//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CODECNAME_H
#define INCLUDE_OTCHI_EBML_CODECNAME_H

#include "otchi_ebml/elements/ebml_element_utf8.h"

namespace otchi_ebml {

    constexpr EBMLId CodecNameId = 0x258688;

    class CodecName : public EBMLElement<EBMLType::kUTF8> {
    public:
        using EBMLElement<EBMLType::kUTF8>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "CodecName";
        }

        [[nodiscard]] EBMLId getId() const override {
            return CodecNameId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\CodecName)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class CodecNameFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new CodecName(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CODECNAME_H
