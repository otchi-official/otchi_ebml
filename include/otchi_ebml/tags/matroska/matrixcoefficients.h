//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_MATRIXCOEFFICIENTS_H
#define INCLUDE_OTCHI_EBML_MATRIXCOEFFICIENTS_H

#include "otchi_ebml/elements/ebml_element_uint.h"

namespace otchi_ebml {

    constexpr EBMLId MatrixCoefficientsId = 0x55B1;

    class MatrixCoefficients : public EBMLElement<EBMLType::kUInt> {
    public:
        using EBMLElement<EBMLType::kUInt>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "MatrixCoefficients";
        }

        [[nodiscard]] EBMLId getId() const override {
            return MatrixCoefficientsId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Tracks\\TrackEntry\\Video\\Colour\\MatrixCoefficients)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class MatrixCoefficientsFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new MatrixCoefficients(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_MATRIXCOEFFICIENTS_H
