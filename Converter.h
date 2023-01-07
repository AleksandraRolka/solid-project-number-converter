#pragma once
#include <iostream>
#include <memory>
#include "ConversionStrategy.h"
#include "exceptions/ConverterException.h"

class Converter
{
private:
    std::unique_ptr<ConversionStrategy> strategy;
    
public:
    explicit Converter() {}

    Converter(std::unique_ptr<ConversionStrategy>& strategy) : strategy(std::move(strategy)) {}

    void setConversionType(std::unique_ptr<ConversionStrategy>& strategy)
    {
        this->strategy = std::move(strategy);
    }

    std::string convert(std::string number) const
    {
        if (!strategy) 
            throw ConverterException("Conversion type not set.");
        return strategy->convert(number);
    }
};