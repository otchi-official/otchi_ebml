//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_SIMPLEBLOCK_H
#define INCLUDE_OTCHI_EBML_SIMPLEBLOCK_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId SimpleBlockId = 0xA3;

    class SimpleBlock : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "SimpleBlock";
        }

        [[nodiscard]] EBMLId getId() const override {
            return SimpleBlockId;
        }

        [[nodiscard]] std::string getPath() const override {
            return R"(0*(\Segment\Cluster\SimpleBlock))";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }

        void decode(std::ifstream &ifstream) override {
            // TODO: Implement decoding for simple block
        }
    };

    class SimpleBlockFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new SimpleBlock(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_SIMPLEBLOCK_H
