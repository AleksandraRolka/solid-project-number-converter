#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "../exceptions/ConversionTypeNotSupportedException.h"
#include "conversions/DecimalToBinary.h"
#include "conversions/BinaryToDecimal.h"

class ConversionsMapper
{
private:
    std::map<std::pair<std::string, std::string>, std::unique_ptr<ConversionStrategy>> availableConversions;

    void initAvailableConversionsMap()
    {
        availableConversions.emplace(std::make_pair("binary", "decimal"), std::make_unique<BinaryToDecimal>());
        availableConversions.emplace(std::make_pair("decimal", "binary"), std::make_unique<DecimalToBinary>());
    }

public:
    explicit ConversionsMapper()
    {
        initAvailableConversionsMap();
    }

    std::unique_ptr<ConversionStrategy> mapToConversionType(std::string fromType, std::string toType)
    {
        auto conversion = availableConversions.find(std::move(std::make_pair(fromType, toType)));
        if (conversion == availableConversions.end())
            throw ConversionTypeNotSupportedException();
        return std::move(conversion->second);
    }
};