#pragma once

class BinaryToDecimal : public ConversionStrategy
{
private:
    bool validateNumberToConvert(std::string number) const override
    {
        for (char c : number) {
            if (!(c == '0' || c == '1'))
                return false;
        }
        return true;
    }
    
public:
    std::string convert(std::string binaryRepresentation) const override
    {
        if (!validateNumberToConvert(binaryRepresentation))
            throw NumberRepresentationException("Invalid value for binary representation.");
        std::string decimalRepresentation = std::to_string( std::stoll(binaryRepresentation, nullptr, 2) );
        return decimalRepresentation;
    }
};