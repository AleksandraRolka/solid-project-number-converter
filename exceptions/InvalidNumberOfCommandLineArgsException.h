
#pragma once
#include <iostream>

class InvalidNumberOfCommandLineArgsException: public std::exception 
{
public:
    explicit InvalidNumberOfCommandLineArgsException() {};
    const char* what() const noexcept override {
        return "Invalid number of args..";
    }
};