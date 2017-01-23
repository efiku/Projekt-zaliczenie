#pragma once
#include <string>
#include <map>
#include "ExceptionResolver.h"
class Definitions
{
    std::map<std::string, std::string> translations;
    ExceptionResolver except;
public:
    Definitions(ExceptionResolver e );
    Definitions();
    ~Definitions();
    std::string getTranslation(std::string type);
    std::string getCodeTranslations(int code);
};

