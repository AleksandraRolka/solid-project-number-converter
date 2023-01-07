#pragma once
#include "../ConversionStrategy.h"
#include "../validators/BinaryValidator.h"
#include "../exceptions/InvalidNumberRepresentationException.h"

class BinaryToDecimal : public ConversionStrategy
{
private:
    std::unique_ptr<BinaryValidator> validator;
    
public:
    explicit BinaryToDecimal() : validator(std::move(std::make_unique<BinaryValidator>())) {}

    std::string convert(std::string binaryRepresentation) const override
    {
        if (!validator->validate(binaryRepresentation))
            throw InvalidNumberRepresentationException("Invalid value for binary representation.");
        std::string decimalRepresentation = std::to_string( std::stoll(binaryRepresentation, nullptr, 2) );
        return decimalRepresentation;
    }
};