
#pragma once
#include <iostream>

class NumberRepresentationException: public std::exception {
private:
    std::string message;
public:
    explicit NumberRepresentationException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};