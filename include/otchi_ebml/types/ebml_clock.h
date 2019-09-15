//
// Created by jmparavicini on 9/9/19.
//

#ifndef INCLUDE_OTCHI_EBML_EBML_CLOCK_H
#define INCLUDE_OTCHI_EBML_EBML_CLOCK_H

#include <chrono>

namespace otchi_ebml {

    struct EbmlClock {
        typedef std::chrono::nanoseconds duration;
        typedef duration::rep rep;
        typedef duration::period period;
        typedef std::chrono::time_point<EbmlClock> time_point;
        static const bool is_steady = false;

        static constexpr typename std::chrono::system_clock::time_point epoch
                = typename std::chrono::system_clock::time_point(std::chrono::seconds(946684800));

        static time_point from_time_t(time_t t) {
            return time_point(std::chrono::system_clock::from_time_t(t) - epoch);
        }

    };
}

#endif //INCLUDE_OTCHI_EBML_EBML_CLOCK_H
