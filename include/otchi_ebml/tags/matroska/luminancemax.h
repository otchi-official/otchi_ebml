//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_LUMINANCEMAX_H
#define INCLUDE_OTCHI_EBML_LUMINANCEMAX_H

#include "otchi_ebml/elements/ebml_element_double.h"

namespace otchi_ebml {

    constexpr EBMLId LuminanceMaxId = 0x55D9;

    class LuminanceMax : public EBMLElement<EBMLType::kDouble> {
    public:
        using EBMLElement<EBMLType::kDouble>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "LuminanceMax";
        }

        [[nodiscard]] EBMLId getId() const override {
            return LuminanceMaxId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\MasteringMetadata\\LuminanceMax)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class LuminanceMaxFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new LuminanceMax(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_LUMINANCEMAX_H
