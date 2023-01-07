#pragma once
#include <iostream>

class Validator
{
public:
    virtual bool validate(std::string number) const = 0;   
};