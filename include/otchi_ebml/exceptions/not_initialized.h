//
// Created by jorge on 9/15/2019.
//

#ifndef INCLUDE_OTCHI_EBML_NOT_INITIALIZED_H
#define INCLUDE_OTCHI_EBML_NOT_INITIALIZED_H

#include <exception>
#include <string>
#include <utility>

struct NotInitialized : public std::exception {
private:
    std::string message_;

public:

    explicit NotInitialized(std::string message) : message_{std::move(message)} {}

    [[nodiscard]] const char *what() const noexcept override {

        return ("Not Initialized Exception: " + message_).c_str();
    }
};


#endif //INCLUDE_OTCHI_EBML_NOT_INITIALIZED_H
