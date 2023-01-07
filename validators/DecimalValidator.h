#pragma once
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "../Validator.h"

class DecimalValidator : public Validator
{
public:
    bool validate(std::string number) const
		{
				long long int num;
        try {
            num = boost::lexical_cast<long long int>(number);
        } catch (boost::exception const& e) {
            return false;
        }
				if (num < 0)
					return false;
        return true;
		} 
};