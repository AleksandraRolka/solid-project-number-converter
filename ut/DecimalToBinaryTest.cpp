#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../converter/conversions/DecimalToBinary.h"
#include "../exceptions/InvalidNumberRepresentationException.h"

class DecimalToBinaryTest : public ::testing::Test
{
protected:
    DecimalToBinary sut = DecimalToBinary();
    std::string validDecimalNumber{"375"};
    std::string invalidDecimalNumber{"37.5"};
};

TEST_F(DecimalToBinaryTest, shouldConvertDecimalToBinaryNumberWhenValidDecimalNumberIsPassed)
{
    std::string decimalNumberRepresentation = sut.convert(validDecimalNumber);
    EXPECT_EQ(decimalNumberRepresentation, "101110111");
}

TEST_F(DecimalToBinaryTest, shouldThrowExceptionWhenAttemptToConvertDecimalToBinaryNumberWhenInvalidDecimalNumberIsPassed)
{
    try
    {
        sut.convert(invalidDecimalNumber);
        FAIL();
    }
    catch (const InvalidNumberRepresentationException &e)
    {
        ASSERT_STREQ("Invalid number for (positive value) decimal representation. Check format and range.", e.what());
    }
}
