#include <iostream>
#include"shape.h"

int main()
{
    int choice;

    while (true)
    {
        std::cout << "Choose a shape: " << std::endl;
        std::cout << "1 - Rectangular" << std::endl;
        std::cout << "2 - Square" << std::endl;
        std::cout << "3 - Circle" << std::endl;
        std::cout << "4 - Triangle" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "Your choice: " << std::endl;
        std::cin >> choice;

        
        if (choice == 1)
        {
            double w, l;
            std::cout << "Print width and length: " << std::endl;
            std::cin >> w >> l;
            Rectangular rec(w, l);
            std::cout << rec << std::endl;
        }
        else if (choice == 2)
        {
            double side;
            std::cout << "Print side: " << std::endl;
            std::cin >> side;
            Squar sq(side);
            std::cout << sq << std::endl;
        }
        else if (choice == 3)
         {
            double r;
            std::cout << "Print radius: " << std::endl;
            std::cin >> r;
            Circle circ(r);
            std::cout << circ << std::endl;
         }
         else if (choice == 4)
        {
            double a, b, c;
            std::cout << "Print three sides: " << std::endl;
            std::cin >> a >> b >> c;
            Triangle tri(a, b, c);
            std::cout << tri << std::endl;
         }
        else
        {
            std::cout << "Try again" << std::endl;
        }
    }

    return 0;
}