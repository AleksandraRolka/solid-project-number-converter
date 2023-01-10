#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../validators/BinaryValidator.h"


class BinaryValidatorTest : public ::testing::Test 
{
protected:
	BinaryValidator sut;
	std::string validBinaryNumber{"111101011001"};
	std::string invalidBinaryNumber{"111101012001"};
};

TEST_F(BinaryValidatorTest, shouldPassValidationWhenValidBinaryNumberIsPassed) 
{
	EXPECT_TRUE(sut.validate(validBinaryNumber));
}

TEST_F(BinaryValidatorTest, shouldNotPassValidationWhenInvalidBinaryNumberIsPassed) 
{
	EXPECT_FALSE(sut.validate(invalidBinaryNumber));
}
