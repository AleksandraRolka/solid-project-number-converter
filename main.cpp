#include <iostream>
#include <memory>
#include "Converter.h"
#include "ConversionsMapper.h"
#include "exceptions/InvalidNumberOfCommandLineArgsException.h"


int main(int argc, char** argv)
{
    if (argc != 4) 
        throw InvalidNumberOfCommandLineArgsException();  

    std::string numberToConvert = argv[1];
    std::string fromType = argv[2];
    std::string toType = argv[3];

    std::unique_ptr<ConversionsMapper> mapper = std::make_unique<ConversionsMapper>();
    std::unique_ptr<ConversionStrategy> conversionStrategy = mapper->mapToConversionType(fromType, toType);
    
    Converter converter = Converter(conversionStrategy);
    std::cout << converter.convert(numberToConvert) << "\n";

    return 0;
}