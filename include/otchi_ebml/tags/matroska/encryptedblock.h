//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_ENCRYPTEDBLOCK_H
#define INCLUDE_OTCHI_EBML_ENCRYPTEDBLOCK_H

#include "otchi_ebml/elements/ebml_element_binary.h"

namespace otchi_ebml {

    constexpr EBMLId EncryptedBlockId = 0xAF;

    class EncryptedBlock : public EBMLElement<EBMLType::kBinary> {
    public:
        using EBMLElement<EBMLType::kBinary>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EncryptedBlock";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EncryptedBlockId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*(\\Segment\\Cluster\\EncryptedBlock)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class EncryptedBlockFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new EncryptedBlock(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_ENCRYPTEDBLOCK_H
