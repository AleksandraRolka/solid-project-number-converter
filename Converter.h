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
        strategy = std::move(strategy);
    }

    void convert(std::string number) const
    {
        if (!strategy) 
            throw ConverterException("Conversion type not set.");
        std::cout << strategy->convert(number) << "\n";
    }
};