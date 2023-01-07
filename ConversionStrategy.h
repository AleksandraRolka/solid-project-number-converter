#pragma once
#include <iostream>
#include "Validator.h"

class ConversionStrategy
{
private:
    std::unique_ptr<Validator> validator;
public:
    virtual std::string convert(std::string number) const = 0;   
};