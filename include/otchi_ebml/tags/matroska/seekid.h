//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEEKID_H
#define INCLUDE_OTCHI_EBML_SEEKID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi {

    constexpr ebml_id SeekIDId = 0x53AB;

    class SeekID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SeekID";
        }

        [[nodiscard]] ebml_id getId() const override {
            return SeekIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\Segment\\SeekHead\\Seek\\SeekID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SeekIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(ebml_size idSize, ebml_size dataSize, ebml_size dataContentSize,
                                ebml_position position) override {
            return new SeekID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEEKID_H
