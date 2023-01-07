#pragma once
#include <iostream>
#include <memory>
#include <map>
#include "exceptions/ConversionTypeNotSupported.h"
#include "conversions/DecimalToBinary.h"
#include "conversions/BinaryToDecimal.h"


class ConversionsMapper
{
private:
    std::map<std::pair<std::string, std::string>, std::unique_ptr<ConversionStrategy>> availableConversions;
    std::unique_ptr<ConversionStrategy> conversionType;

    void initAvailableConversionsMap() {
        availableConversions.emplace(std::make_pair("binary", "decimal"), std::make_unique<BinaryToDecimal>());
        availableConversions.emplace(std::make_pair("decimal", "binary"), std::make_unique<DecimalToBinary>());
    }

public:
    ConversionsMapper(std::string fromType, std::string toType)
    {
        initAvailableConversionsMap();
        auto conversion = availableConversions.find(std::move( std::make_pair(fromType, toType) ));
        if (conversion == availableConversions.end()) 
            throw ConversionTypeNotSupported();           
        conversionType = std::move(conversion->second);
    }
    std::unique_ptr<ConversionStrategy> getConversionType()
    {
        return std::move(conversionType);
    }
};