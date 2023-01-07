
#pragma once
#include <iostream>

class ConverterException: public std::exception {
private:
    std::string message;
public:
    explicit ConverterException(const std::string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};