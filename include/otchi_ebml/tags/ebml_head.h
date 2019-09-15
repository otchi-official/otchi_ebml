//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_HEAD_H
#define INCLUDE_OTCHI_EBML_EBML_HEAD_H

#include "otchi_ebml/elements/ebml_element_master.h"

namespace otchi_ebml {

    constexpr EBMLId EBMLHeadID = 0x1A45DFA3;

    class EBMLHead : public EBMLElement<EBMLType::kMaster> {
    public:
        using EBMLElement<EBMLType::kMaster>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EBML Head";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EBMLHeadID;
        }

        [[nodiscard]] EBMLPath getPath() const override {
            return EBMLPath("1*1(\\EBML)");
        }

        [[nodiscard]] int minOccurs() const override {
            return 1;
        }

        [[nodiscard]] std::optional<int> maxOccurs() const override {
            return 1;
        }

        [[nodiscard]] std::string getDescription() const override {
            return "Set the EBML characteristics of the data to follow. Each EBML Document has to start with this.";
        }
    };

    class EBMLHeadFactory: public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLIdSize idSize, EBMLDataSize dataSize, EBMLContentSize dataContentSize) override {
            return new EBMLHead(idSize, dataSize, dataContentSize);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_HEAD_H