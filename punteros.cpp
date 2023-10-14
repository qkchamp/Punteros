
#include <iostream> //Input/Output.
#include <string> //string f.
#include <cstdlib> //Malloc.
#include <stdio.h> //free().
#include <windows.h> //font colours.
#include <unordered_map> //Hash Table.
#include <functional> //Lambda.
#include <sstream> //iss.
#include "mainHeader.h" // cpp > cpp with Main().

std::string totalChars_string;
int totalChars = 0;
int fPtr = 0;

int main()
{
    /*
    * Important Notes:
    *
    * Smart pointers were not used.
    * hConsole = STD_OUTPUT_HANDLE (buffer)
    * GetConsoleScreenBufferInfo = Actual Buffer Info. Only used once to get console default text cfg.
    * TextColours = All possible colours to use in cmd text buffer.
    * ptr_n1 = (int*)malloc(sizeof(int) * 10); = ptr_n1[] max 10.
    * SetConsoleTextAttribute(hConsole, originalAttributes.wAttributes) =  used to restore the console's text attributes (such as text color and background color)
    * to their original values after they have been changed using the SetConsoleTextAttribute function.
    */

    /*
   * Definition of HANDLE type + originalAttributes = ScreenBufferInfo Default.
  */
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO originalAttributes;
    GetConsoleScreenBufferInfo(hConsole, &originalAttributes);

    std::unordered_map<std::string, std::function<void()>> TextColours;

    TextColours["default"] = [&hConsole, &originalAttributes]() {SetConsoleTextAttribute(hConsole, originalAttributes.wAttributes); };
    TextColours["green"] = [&hConsole]() {SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); };
    TextColours["red"] = [&hConsole]() {SetConsoleTextAttribute(hConsole, FOREGROUND_RED); };
    TextColours["blue"] = [&hConsole]() {SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); };
    TextColours["intensity"] = [&hConsole]() {SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY); };

    
    int* n1 = nullptr, * n2 = nullptr;
    int* ptr_n1 = nullptr;
    n1 = (int*)malloc(sizeof(int) * 10);
    n2 = (int*)malloc(sizeof(int) * 10);
    ptr_n1 = (int*)malloc(sizeof(int) * 10);
    std::string* n1_string = new std::string, * n2_string = new std::string;
    const int bucle = 5; //For loop.

    /*
    * Verify dynamic memory allocation success.
    */
    if (ptr_n1 == nullptr and n1 == nullptr and n2 == nullptr) {

        TextColours["red"]();

        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }
    else
    {

        TextColours["green"]();
        std::cerr << "Memory allocation succesfully." << std::endl;

    }

    TextColours["default"]();
    //std::cout << "Enter a number: ";
    //std::cin >> n1;


    getValidNumberInput(n1_string);
    const char* Auxptr_1 = n1_string->c_str(); //Convert std::string* to const char*
    *n1 = std::stoi(Auxptr_1);



    ptr_n1[0] = *n1;
    TextColours["blue"]();
    std::cout << "The [1] pointer M-A is: " << &ptr_n1[0] << std::endl;
    std::cout << "Value 1: " << ptr_n1[0] << std::endl;
    TextColours["default"]();
    //std::cout << "Enter a 2nd number: ";
   // std::cin >> n2;

    getValidNumberInput(n2_string);
    const char* Auxptr_2 = n2_string->c_str();
    *n2 = std::stoi(Auxptr_2);


    ptr_n1[1] = *n2;
    TextColours["blue"]();
    std::cout << "The [2] pointer M-A is: " << &ptr_n1[0] << std::endl;
    std::cout << "Value 2: " << ptr_n1[1] << std::endl;

    if (totalChars != 0)
    {
        TextColours["green"]();
        std::cout << "Ammount of chars deleted: " << totalChars << std::endl;
        TextColours["red"]();
        std::cout << "List of chars deleted: " << "[" << totalChars_string << "]" << std::endl;
    }
    else { TextColours["green"](); std::cout << "No characters found in the inputs." << std::endl; }


    TextColours["intensity"]();
    std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "FOR LOOP ([0] n+1 , [1] n+1)" <<std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------------------" << std::endl;
    TextColours["blue"]();

    int sum,neosum;
    sum = ptr_n1[0] + ptr_n1[1];

    for (int i = 0; i < bucle; i++) 
    {
        ptr_n1[0] += 1;
        ptr_n1[1] += 1;
        std::cout << "Valor" << "(" + std::to_string(i) + ")" << ptr_n1[0]  << "," << ptr_n1[1] << std::endl;
        std::cout << "Memoria" << "(" + std::to_string(i) + ")" << &ptr_n1[0]<< "," << &ptr_n1[1] << std::endl;
        
    }

    TextColours["red"]();
    std::cout << "Sum of two numbers (before the loop): " << sum <<std::endl;
    neosum = ptr_n1[0] + ptr_n1[1];
    TextColours["green"]();
    std::cout << "Sum of two numbers (after the loop): " << neosum << std::endl;
   

    TextColours["intensity"]();
    std::cout << "-------------------------------------------------------------------------------------------------------------------" << std::endl;

    TextColours["default"]();
    std::cout << "Cleaning all the pointers..." << std::endl;

    // Clean all pointers.
    freeMemory(ptr_n1); freeMemory(n1); freeMemory(n2);
    

    /*
    * Check if memory was cleaned correctly, a better option to validate this is using a loop in a dictionary who allocates all the available pointers, after the loop
    * this should return a Bool.
    *  Total Pointers = 8 (Hardcoded). Six counting auxUI from "numberValdiation.cpp".
    */ 

    if (fPtr == 5) {
        TextColours["green"]();
        std::cout << "Memory cleaned succesfully." << std::endl << "Ptrs cleaned: " << fPtr << std::endl;
    }
    else {
        TextColours["red"]();
        std::cerr << "Memory for some reason cant be cleaned." << std::endl;
        std::cerr << "Debug: " << fPtr << std::endl;
    }

    TextColours["default"]();
    

}