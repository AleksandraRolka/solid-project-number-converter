#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../Converter.h"
#include "../conversions/DecimalToBinary.h"
#include "../conversions/BinaryToDecimal.h"
#include "../exceptions/ConverterException.h"
#include "../exceptions/InvalidNumberRepresentationException.h"


class ConverterTest : public ::testing::Test 
{
protected:
   Converter sut;
   std::string validDecimalNumber{"375"};
   std::string invalidDecimalNumber{"37.5"};
   std::string validBinaryNumber{"10111101101"};
   std::string invalidBinaryNumber{"10112101101"};
   std::unique_ptr<ConversionStrategy> decimalToBinaryConversion = std::make_unique<DecimalToBinary>();
   std::unique_ptr<ConversionStrategy> binaryToDecimalConversion = std::make_unique<BinaryToDecimal>();
};

TEST_F(ConverterTest, shouldThrowConverterExceptionWhenAttemptToConvertWithConversionStategyNotSet) 
{
   try {
      sut.convert(validDecimalNumber);
      FAIL();
   } catch (const ConverterException& e) {
      ASSERT_STREQ("Conversion type not set.", e.what());
   }
}

TEST_F(ConverterTest, shouldConvertDecimalToBinaryNumberWhenProperStategyIsSetAndValidNumberIsPassed) 
{
   sut.setConversionType(decimalToBinaryConversion);
   std::string binaryNumberRepresentation = sut.convert(validDecimalNumber);
   EXPECT_EQ(binaryNumberRepresentation, "101110111");
}

TEST_F(ConverterTest, shouldConvertBinaryToDecimalNumberWhenProperStategyIsSetAndValidNumberIsPassed) 
{
   sut.setConversionType(binaryToDecimalConversion);
   std::string decimalNumberRepresentation = sut.convert(validBinaryNumber);
   EXPECT_EQ(decimalNumberRepresentation, "1517");
}

TEST_F(ConverterTest, shouldThrowInvalidNumberRepresentationExceptionWhenAttemptToConvertInvalidDecimalNumber) 
{
   sut.setConversionType(decimalToBinaryConversion);
   EXPECT_THROW(sut.convert(invalidDecimalNumber), InvalidNumberRepresentationException);
}

TEST_F(ConverterTest, shouldThrowInvalidNumberRepresentationExceptionWhenAttemptToConvertInvalidBinaryNumber) 
{
   sut.setConversionType(binaryToDecimalConversion);
   EXPECT_THROW(sut.convert(invalidDecimalNumber), InvalidNumberRepresentationException);
}
