
#pragma once
#include <iostream>

class ConversionTypeNotSupportedException: public std::exception 
{
public:
    explicit ConversionTypeNotSupportedException() {};
    const char* what() const noexcept override {
        return "Conversion type not supported...";
    }
};