#pragma once
#include <bitset>
#include <boost/lexical_cast.hpp>
#include <boost/exception/diagnostic_information.hpp>
#include "../exceptions/NumberRepresentationException.h"

class DecimalToBinary : public ConversionStrategy
{
private:
    bool validateNumberToConvert(std::string number) const override
    {
        try {
            boost::lexical_cast<long long int>(number);
        } catch(boost::exception const& e) {
            return false;
        }
        return true;
    }
    
    static std::string removeLeadingZeros(std::string binaryNumber) 
    {
        return binaryNumber.erase(0, binaryNumber.find_first_not_of('0'));
    }

public:
    std::string convert(std::string decimalRepresentation) const override
    {
        if (!validateNumberToConvert(decimalRepresentation))
            throw NumberRepresentationException("Invalid number for decimal representation. Check format and range");
        std::string binaryRepresentation = std::bitset<64>(std::stoll(decimalRepresentation, nullptr, 10)).to_string();
        binaryRepresentation = removeLeadingZeros(binaryRepresentation);
        return binaryRepresentation;
    }
};