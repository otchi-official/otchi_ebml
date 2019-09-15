//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_ELEMENT_DATE_H
#define INCLUDE_OTCHI_EBML_EBML_ELEMENT_DATE_H

#include <chrono>

#include "ebml_element.h"
#include "ebml_element_factory.h"
#include "otchi_ebml/exceptions/not_initialized.h"

namespace otchi_ebml {

    using EBMLClock = std::chrono::system_clock;

    template<>
    class EBMLElement<EBMLType::kDate> : public EBMLBaseElement {
        std::optional<EBMLClock::time_point> value_;

    public:

        using EBMLBaseElement::EBMLBaseElement;

        EBMLType getType() override {
            return EBMLType::kDate;
        }

        void decode(std::ifstream ifstream) override {
            using namespace std::chrono;

            auto buffer = new unsigned char[getContentSize()];
            ifstream.read(reinterpret_cast<char *>(buffer), getContentSize());
            int nano{0};
            for (unsigned int i = 0; i < getContentSize(); i++) {
                nano += buffer[i] << 8u * (getContentSize() - i - 1);
            }

            auto n = duration_cast<system_clock::duration>(nanoseconds(nano));
            auto epoch = duration_cast<system_clock::duration>(nanoseconds(978303600000000000));

            auto t = duration_cast<seconds>(n + epoch);
            auto g = system_clock::from_time_t(t.count());
            value_ = g;
        }

        [[nodiscard]] EBMLClock::time_point getValue() const {
            if (value_ == std::nullopt)
                throw NotInitialized("Trying to get value of object before it was decoded");
            return value_.value();
        }
    };

}

#endif //INCLUDE_OTCHI_EBML_EBML_ELEMENT_DATE_H
