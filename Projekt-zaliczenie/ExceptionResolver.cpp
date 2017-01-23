#include "stdafx.h"
#include "ExceptionResolver.h"


ExceptionResolver::ExceptionResolver()
{
    exceptions[1] = std::string("Przekroczono zakres elementu!");
    exceptions[2] = std::string("Nie ma nic do usuniêcia.");
    exceptions[3] = std::string("Wektor o podanym indeksie nie zosta³ znaleziony");
    exceptions[4] = std::string("Rozmiar 0 nie jest poprawn¹ wartoœci¹");

}


ExceptionResolver::~ExceptionResolver()
{
}


std::string ExceptionResolver::translateCode(int code)
{ 
    std::map<int, std::string>::iterator it = exceptions.begin();
    while (it != exceptions.end())
    {
        if (it->first == code)
            return it->second;
        it++;
    }
    return "";
}
