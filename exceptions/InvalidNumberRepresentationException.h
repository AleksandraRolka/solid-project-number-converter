
#pragma once
#include <iostream>

class InvalidNumberRepresentationException: public std::exception {
private:
    std::string message;
public:
    explicit InvalidNumberRepresentationException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};