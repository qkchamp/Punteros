#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>
#include "mainHeader.h"

extern std::string totalChars_string;
extern int totalChars;
extern int fPtr;
std::string* auxUI = new std::string;
std::string  strInput;
/*
* Para agregar:
* - Validar la cadena de caracteres entera.
*/
void getValidNumberInput(std::string*& userInput) {

    bool haveNumbers = false;
    bool nullDeleted = false;

    while (!haveNumbers) {
        std::cout << "Enter a number: ";
        std::getline(std::cin, strInput);
        auxUI = userInput;
        userInput = &strInput;


        if (std::cin.fail()) { std::cout << "Error: Null.";  break; }

        for (char c : *userInput) {

            if (std::isdigit(c))
            {
                userInput->erase(std::remove_if(userInput->begin(), userInput->end(), [](char c)
                    {
                        return std::isalpha(c);
                    }), userInput->end());
                haveNumbers = true;
            }
        }

        if (haveNumbers == true) {
            for (char c : *auxUI) {
                if (std::isalpha(c)) {
                    totalChars_string += c;
                    totalChars += 1;
                }

            }
            freeMemory(auxUI);
            break;
            
        }
    }
}

// Memory Allocation methods.

void freeMemory(int*& ptr) // int pointers.
{
    
    delete ptr;
    ptr = nullptr;
    fPtr += 1;

}

void freeMemory(std::string*& ptr) // string pointers.
{

    delete ptr;
    ptr = nullptr;
    fPtr += 1;

}

/*
* 
* OBSOLETE. NOT NEEDED
* 

void freeMemory(const char*& ptr) // const pointers.
{

    delete ptr;
    ptr = nullptr;
    fPtr += 1;

}
*/