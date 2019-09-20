//
// Created by Jorge Paravicini on 2019-09-20
// Copyright (c) 2019 Otchi Org. All Rights reserved
//

#ifndef INCLUDE_OTCHI_EBML_DATEUTC_H
#define INCLUDE_OTCHI_EBML_DATEUTC_H

#include "otchi_ebml/elements/ebml_element_date.h"

namespace otchi_ebml {

    constexpr EBMLId DateUTCId = 0x4461;

    class DateUTC : public EBMLElement<EBMLType::kDate> {
    public:
        using EBMLElement<EBMLType::kDate>::EBMLElement;

        [[nodiscard]] std::string getName() const override {
            return "DateUTC";
        }

        [[nodiscard]] EBMLId getId() const override {
            return DateUTCId;
        }

        [[nodiscard]] std::string getPath() const override {
            return "0*1(\\Segment\\Info\\DateUTC)";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "";
        }
    };

    class DateUTCFactory : public IEBMLElementFactory {
    public:
        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,
                                EBMLPosition position) override {
            return new DateUTC(idSize, dataSize, dataContentSize, position);
        }
    };
}

#endif //INCLUDE_OTCHI_EBML_DATEUTC_H
