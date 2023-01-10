#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../converter/ConversionsMapper.h"
#include "../converter/conversions/ConversionStrategy.h"
#include "../converter/conversions/DecimalToBinary.h"
#include "../converter/conversions/BinaryToDecimal.h"
#include "../exceptions/ConversionTypeNotSupportedException.h"

template <typename Base, typename T>
inline bool instanceof (const T *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

class ConversionsMapperTest : public ::testing::Test
{
protected:
    ConversionsMapper sut = ConversionsMapper();
    std::pair<std::string, std::string> validDecimalBinaryTypeNamePair = std::make_pair("decimal", "binary");
    std::pair<std::string, std::string> validBinaryDecimalTypeNamePair = std::make_pair("binary", "decimal");
    std::pair<std::string, std::string> notSupportedTypesNamePair = std::make_pair("binary", "hexadecimal");
};

TEST_F(ConversionsMapperTest, shouldReturnDecimalToBinaryConversionStrategy)
{
    auto strategy = sut.mapToConversionType(validDecimalBinaryTypeNamePair.first, validDecimalBinaryTypeNamePair.second);
    ASSERT_TRUE(std::move(dynamic_cast<DecimalToBinary *>(strategy.get())));
}

TEST_F(ConversionsMapperTest, shouldReturnBinaryToDecimalConversionStrategy)
{
    auto strategy = sut.mapToConversionType(validBinaryDecimalTypeNamePair.first, validBinaryDecimalTypeNamePair.second);
    ASSERT_TRUE(std::move(dynamic_cast<BinaryToDecimal *>(strategy.get())));
}

TEST_F(ConversionsMapperTest, shouldThrowConversionTypeNotSupportedException)
{
    try
    {
        sut.mapToConversionType(notSupportedTypesNamePair.first, notSupportedTypesNamePair.second);
        FAIL();
    }
    catch (const ConversionTypeNotSupportedException &e)
    {
        ASSERT_STREQ("Conversion type not supported...", e.what());
    }
}
