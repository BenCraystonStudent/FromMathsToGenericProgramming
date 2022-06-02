#include <iostream>
#include "AhmesAlgorithm.h"


    int multiply0(int n, int a)
    {
        if (n == 1)
        {
            return a;
        }
        return multiply0(n - 1, a) + a;

        //n == 4
        //a == 5

        //n == 3
        //a == 5 + 5

        //n == 2
        //a == 5 + 5 + 5

        //n == 1
        //a == 5 + 5 + 5 + 5

        //uses recursion
    }

    int main()
    {
        Ahmes ahmes;
        int x = multiply0(4, 5);
        std::cout << x << std::endl;
        int y = ahmes.multiply_by_15(5);
        int z = ahmes.multiplayUnknown(5);
        std::cout << y << std::endl;
        std::cout << z << std::endl;
        return 0;
    }

    


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
