#pragma once
#include  <map>
class ExceptionResolver
{
    std::map<int, std::string> exceptions;
public:
    ExceptionResolver();
    ~ExceptionResolver();
    std::string translateCode(int code);
};

