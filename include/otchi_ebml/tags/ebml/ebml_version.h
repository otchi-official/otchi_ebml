//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_VERSION_H
#define INCLUDE_OTCHI_EBML_EBML_VERSION_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId EBMLVersionId = 0x4286;

    class EBMLVersion : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "EBMLVersion";
        }

        [[nodiscard]] EBMLId getId() const override {
            return EBMLVersionId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "1*1(\\EBML\\EBMLVersion)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "Set the EBML characteristics of the data to follow. Each EBML Document has to start with this.";
        }
    };

    class EBMLVersionFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new EBMLVersion(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_VERSION_H
