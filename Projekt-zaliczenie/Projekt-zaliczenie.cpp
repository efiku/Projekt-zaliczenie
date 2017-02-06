// Projekt-zaliczenie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <exception>
#include <ctime>
#include <algorithm>
#include "MyVector.h"
#include <assert.h>  
#include "node.h"
#include "find.h"
#include "Application.h"
#include "ExceptionResolver.h"
#include "Definitions.h"
#include <fstream>

using namespace std;
void makeTests();
int main()
{
    makeTests();
    Application app;
    ExceptionResolver excetions;
    Definitions definitions(excetions);

    MyVector<node> container(20);
    node  inputObject;
    node *findObject = NULL;
    fstream fin, fout;
    fout.close();
    fin.close();
    while (app.run()) {
        int option;
        system("cls");
        cout << definitions.getTranslation("menu");
        cin >> option;
        system("cls");
        switch (option)
        {
        default:
            break;

        case 1:
            cout << definitions.getTranslation("node_description");
            cin >> inputObject;
            container.push(inputObject);
            system("pause");
            break;

        case 2:
            cout << definitions.getTranslation("insert_node");
            cout << definitions.getTranslation("node_description");
            cin >> inputObject;
            container.errase(&inputObject);
            break;

        case 3:
            cout << definitions.getTranslation("vector_cleared");
            container.clearAll();
            system("pause");
            break;

        case 4:
            cout << definitions.getTranslation("modify_object");
            cout << definitions.getTranslation("node_description");
            cin >> inputObject;
            findObject = efik::find(container.begin(), container.end(), inputObject);
            if (findObject) {
                system("cls");
                cout << definitions.getTranslation("found");
                cout << definitions.getTranslation("node_description");
                cin >> *findObject;
            }
            else
            {
                cout << definitions.getTranslation("not_found");
            }
            system("pause");

            break;

        case 5:
            cout << definitions.getTranslation("node_description");
            cin >> inputObject;
            cout << definitions.getTranslation("index_after");
            int index;
            cin >> index;
            try
            {
                container.insert(inputObject, index);
            }
            catch (int c)
            {
                cout << definitions.getCodeTranslations(c);
            }
            system("pause");
            break;

        case 6:
            cout << definitions.getTranslation("search_object");
            cout << definitions.getTranslation("node_description");
            cin >> inputObject;
            findObject = efik::find(container.begin(), container.end(), inputObject);
            if (findObject) {
                system("cls");
                cout << *findObject << endl;
            }
            else
            {
                cout << definitions.getTranslation("not_found");
            }
            system("pause");
            break;

        case 7:
            for (int i = 0; i < container.size(); i++) {
                cout << i + 1 << ". " << container[i] << endl;
            }
            system("pause");
            break;




        case 8:
            fout.open("plik.txt", ios::out | ios::trunc);
            fout << container;
            fout.close();
            break;


        case 9:
            fin.open("plik.txt", ios::in);
            fin >> container;
            fin.close();
            break;
        case 10:
            app.toggle();
            break;
        }



    }




    // This code is a total mess, I don't have time to enhance this... 
    // Because of work... 
    // BUT! MyVector class have tests!
    // TODO:  SAVE/READ DATA
    // Copyright: 2017 Krzysztof "efik" Pazdur. 
    return 0;
}

void makeTests()
{
    // Here are all tests for my vector implementation
    MyVector<unsigned int> vector(10);
    std::cout << "Testy \n\n";

    /*
    Test: size / maxsize
    */
    assert(vector.size() == 0);
    assert(vector.getMaxSize() == 10);

    /*
    Test:  Push method
    */
    vector.push(123);
    vector.push(231);
    vector.push(11);
    vector.push(44);

    /*
    Test: Push result test
    */
    assert(vector.size() == 4);
    assert(vector[0] == 123);
    assert(vector[1] == 231);
    assert(vector[2] == 11);
    assert(vector[3] == 44);

    /*
    Test: [] operator test;
    */
    vector[1] = 300;
    vector[3] = 999;

    assert(vector[1] == 300);
    assert(vector[3] == 999);  // 123 300 11 999 

                               /*
                               Test: Errase method with sort.
                               */
    vector.errase(&vector[1]);
    assert(vector.size() == 3);
    assert(vector[0] == 123);
    assert(vector[1] == 11);
    assert(vector[2] == 999);

    /*
    Test: Method find
    */
    unsigned int * ptr = NULL;
    ptr = efik::find(vector.begin(), vector.end(), 999);

    assert(ptr != NULL); // adres
    assert(*ptr == 999); // wartosc
    assert(ptr == &vector[2]);  // adresy 

                                /*
                                @it should return NULL if object is not found
                                */
    ptr = efik::find(vector.begin(), vector.end(), 4999);
    assert(ptr == NULL); // NULL



                         // clearAll PoC
    vector.clearAll();
    assert(vector.size() == 0);

    // Insert after PoC test;
    vector.push(1); // 0
    vector.push(2); // 1
    vector.push(3); // 2
    vector.push(4); // ..
    vector.push(5);
    assert(vector.size() == 5);

    vector.insert(7, 2);

    assert(vector.size() == 6);
    assert(vector[0] == 1);
    assert(vector[1] == 2);
    assert(vector[2] == 7);
    assert(vector[3] == 3);
    assert(vector[4] == 4);
    assert(vector[5] == 5);
    vector.pop();
    assert(vector.size() == 5);
    assert(vector[4] == 4);

}
