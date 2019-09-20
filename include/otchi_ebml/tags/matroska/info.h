//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_INFO_H
#define INCLUDE_OTCHI_EBML_INFO_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId InfoId = 0x1549A966;

    class Info : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "Info";
        }

        [[nodiscard]] EBMLId getId() const override {
            return InfoId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*(\\Segment\\Info)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class InfoFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new Info(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_INFO_H
