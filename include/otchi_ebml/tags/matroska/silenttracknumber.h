//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SILENTTRACKNUMBER_H
#define INCLUDE_OTCHI_EBML_SILENTTRACKNUMBER_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId SilentTrackNumberId = 0x58D7;

    class SilentTrackNumber : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SilentTrackNumber";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SilentTrackNumberId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Cluster\\SilentTracks\\SilentTrackNumber)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SilentTrackNumberFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new SilentTrackNumber(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SILENTTRACKNUMBER_H
