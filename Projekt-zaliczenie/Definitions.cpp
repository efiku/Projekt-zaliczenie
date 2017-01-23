#include "stdafx.h"
#include "Definitions.h"


Definitions::Definitions()
{

}


Definitions::Definitions(ExceptionResolver e)
{
    except = e;
    translations = std::map<std::string, std::string>();

    translations.insert(std::pair<std::string, std::string>("menu",
        "Menu: \n"
        "1. Dodaj obiekt\n"
        "2. Usun obiekt\n"
        "3. Wyczyœæ tablicê obiektów\n"
        "4. Modyfikuj obiekt\n"
        "5. Wstaw obiekt w okreœlone miejsce\n"
        "6. znajdŸ wszystkie obiekty z podanym kluczem\n"
        "7. wyswietl dane na monitorze\n"
        "8. Zakoncz program\n\n"
        "Podaj opcje: "));

    translations["node_description"] = std::string(
        "Numer wierzcho³ka (enter), Nazwa wierzcho³ka (enter), X (enter), T(enter) \n"
    );

    translations["insert_node"] = std::string(
        "Wpisz jaki obiekt chcesz usunac:\n"
    );

    translations["vector_cleared"] = std::string(
        "Wyczyszczono tablice obektow"
    );

    translations["modify_object"] = std::string(
        "Modyfikuj wybrany obiekt"
    );
    translations["found"] = std::string(
        "\nZnaleziono!\n"
    );
    translations["not_found"] = std::string(
        "\nNIE ZNALEZIONY!\n"
    );
    translations["index_after"] = std::string(
        "Teraz podaj jeszcze po jakim indeksie ma siê wstawiæ ten obiekt:"
    );
    translations["search_object"] = std::string(
        "Wyszukaj obiekt"
    );

}

Definitions::~Definitions()
{
}

std::string Definitions::getTranslation(std::string type)
{
    std::map<std::string, std::string>::iterator it = translations.begin();
    while (it != translations.end())
    {
        if (it->first == type)
            return it->second;
        it++;
    }
    return "";
}

std::string Definitions::getCodeTranslations(int code)
{
    return except.translateCode(code);
}
