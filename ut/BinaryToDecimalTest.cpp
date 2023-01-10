#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../converter/conversions/BinaryToDecimal.h"
#include "../exceptions/InvalidNumberRepresentationException.h"

class BinaryToDecimalTest : public ::testing::Test
{
protected:
    BinaryToDecimal sut = BinaryToDecimal();
    std::string validBinaryNumber{"101111011"};
    std::string invalidBinaryNumber{"101121011"};
    std::string outOfRangeBinaryNumber{"11111111111111111111111111111111111111111111111111111111111111111"};
};

TEST_F(BinaryToDecimalTest, shouldConvertBinaryToDecimalNumberWhenValidBinaryNumberIsPassed)
{
    std::string decimalNumberRepresentation = sut.convert(validBinaryNumber);
    EXPECT_EQ(decimalNumberRepresentation, "379");
}

TEST_F(BinaryToDecimalTest, shouldThrowExceptionWhenAttemptToConvertBinaryToDecimalNumberWhenInvalidBinaryNumberIsPassed)
{
    try
    {
        sut.convert(invalidBinaryNumber);
        FAIL();
    }
    catch (const InvalidNumberRepresentationException &e)
    {
        ASSERT_STREQ("Invalid value for binary representation. Check format and range.", e.what());
    }
}

TEST_F(BinaryToDecimalTest, shouldThrowExceptionWhenTooBigBinaryNumberIsPassed)
{
    EXPECT_THROW(sut.convert(outOfRangeBinaryNumber), std::out_of_range);
}
