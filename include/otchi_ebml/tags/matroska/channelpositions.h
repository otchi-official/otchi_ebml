//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_CHANNELPOSITIONS_H
#define INCLUDE_OTCHI_EBML_CHANNELPOSITIONS_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId ChannelPositionsId = 0x7D7B;

    class ChannelPositions : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "ChannelPositions";
        }

        [[nodiscard]] EBMLId getId() const override {
            return ChannelPositionsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Audio\\ChannelPositions)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class ChannelPositionsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new ChannelPositions(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_CHANNELPOSITIONS_H
