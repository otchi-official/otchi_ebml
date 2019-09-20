//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SEEK_H
#define INCLUDE_OTCHI_EBML_SEEK_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId SeekId = 0x4DBB;

    class Seek : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Seek";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SeekId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\SeekHead\\Seek)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class SeekFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Seek(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SEEK_H
