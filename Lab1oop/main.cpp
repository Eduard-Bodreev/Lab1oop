#pragma once
#include "Matrix.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

using namespace Prog1;

int main() {
    int line, number;
    struct Node* initmatr = NULL;
    struct Node* newmatr = NULL;

    do {
        std::cout << "Enter number of lines in your sparse Matrix = ";
        if (!(std::cin >> line))
            return -1;
    } while (line < 1);
    do {
        std::cout << std::endl << "Enter number of items in lines = ";
        if (!(std::cin >> number))
            return -1;
    } while (number < 1);


    initmatr = input(line, number);


    std::cout << "\nOld Matrix\n";
    PrintMatr(initmatr, line, number);

    newmatr = modify(initmatr, line, number);

    std::cout << "\nNew Matrix\n";
    PrintMatr(newmatr, line, number);

    DeleteList(initmatr);
    DeleteList(newmatr);


    _CrtDumpMemoryLeaks();
    return 0;
}





/*

                0 1 2 3 4
              0 5 3 6 7 8
              1
              2 4 5 2 8 8 
              3
              4







*/