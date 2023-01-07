#pragma once
#include <iostream>

class ConversionStrategy
{
private:
    virtual bool validateNumberToConvert(std::string number) const = 0;
public:
    virtual std::string convert(std::string number) const = 0;   
};