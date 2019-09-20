//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_PREVUID_H
#define INCLUDE_OTCHI_EBML_PREVUID_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId PrevUIDId = 0x3CB923;

    class PrevUID : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "PrevUID";
        }

        [[nodiscard]] EBMLId getId() const override {
            return PrevUIDId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Info\\PrevUID)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class PrevUIDFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new PrevUID(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_PREVUID_H
