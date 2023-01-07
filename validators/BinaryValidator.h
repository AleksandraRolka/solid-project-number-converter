#pragma once
#include <iostream>
#include "../Validator.h"

class BinaryValidator : public Validator
{
public:
    bool validate(std::string number) const 
	{
		for (char c : number) {
				if (!(c == '0' || c == '1'))
						return false;
		}
		return true;
	} 
};