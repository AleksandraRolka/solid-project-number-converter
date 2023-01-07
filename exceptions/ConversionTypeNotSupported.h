
#pragma once
#include <iostream>

class ConversionTypeNotSupported: public std::exception 
{
public:
    explicit ConversionTypeNotSupported() {};
    const char* what() const noexcept override {
        return "Conversion type not supported...";
    }
};