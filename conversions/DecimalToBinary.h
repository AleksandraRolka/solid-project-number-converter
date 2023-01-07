#pragma once
#include <bitset>
#include "../ConversionStrategy.h"
#include "../validators/DecimalValidator.h"
#include "../exceptions/InvalidNumberRepresentationException.h"


static std::string removeLeadingZeros(std::string binaryNumber) 
{
    return binaryNumber.erase(0, binaryNumber.find_first_not_of('0'));
}

class DecimalToBinary : public ConversionStrategy
{
private:
    std::unique_ptr<DecimalValidator> validator;
    friend std::string removeLeadingZeros(std::string binaryNumber);

public:
    explicit DecimalToBinary() : validator(std::move(std::make_unique<DecimalValidator>())) {}
    
    std::string convert(std::string decimalRepresentation) const override
    {
        if (!validator->validate(decimalRepresentation))
            throw InvalidNumberRepresentationException("Invalid number for decimal representation. Check format and range");
        std::string binaryRepresentation = std::bitset<64>(std::stoll(decimalRepresentation, nullptr, 10)).to_string();
        binaryRepresentation = removeLeadingZeros(binaryRepresentation);
        return binaryRepresentation;
    }
};