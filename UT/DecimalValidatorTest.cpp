#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "../validators/DecimalValidator.h"


class DecimalValidatorTest : public ::testing::Test 
{
protected:
	DecimalValidator sut;
	std::string validDecimalNumber{"375765845"};
	std::string invalidValueNotDecimalNumber{"37.5"};
	std::string outOfRangeDecimalNumber{"2346568956946726414512456734"};
};

TEST_F(DecimalValidatorTest, shouldPassValidationWhenValidPositiveDecimalNumberIsPassed) 
{
	EXPECT_TRUE(sut.validate(validDecimalNumber));
}

TEST_F(DecimalValidatorTest, shouldNotPassValidationWhenNotDecimalNumberIsPassed) 
{
	EXPECT_FALSE(sut.validate(invalidValueNotDecimalNumber));
}

TEST_F(DecimalValidatorTest, shouldNotPassValidationWhenTooBigDecimalNumberIsPassed) 
{
	EXPECT_FALSE(sut.validate(outOfRangeDecimalNumber));
}

