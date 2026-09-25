#include <iostream>
#include "my_class.h"
#include "zoo.h"

int main()
{
    my_class a;

    std::cout << a.field << std::endl;
    std::cout << a.my_string << std::endl;
    std::cout << "================================" << std::endl;

    my_class b(7, "other");
    a = b;
    std::cout << a.field << std::endl;
    std::cout << a.my_string << std::endl;
    std::cout << b.field << std::endl;
    std::cout << b.my_string << std::endl;
    std::cout << "================================" << std::endl;

    my_class c(b);
    std::cout << c.field << std::endl;
    std::cout << c.my_string << std::endl;
    std::cout << "================================" << std::endl;

    my_class d(std::move(c));
    std::cout << c.field << std::endl;
    std::cout << c.my_string << std::endl;
    std::cout << d.field << std::endl;
    std::cout << d.my_string << std::endl;
    std::cout << "================================" << std::endl;

    c = std::move(a);
    std::cout << a.field << std::endl;
    std::cout << a.my_string << std::endl;
    std::cout << c.field << std::endl;
    std::cout << c.my_string << std::endl;
    std::cout << "================================" << std::endl;

    my_class* base;
    // code
    base = new derivative_class();

    std::cout << "================================" << std::endl;

    //=======================================================
    // Зоопарк
    Animal base_animal;
    base_animal.MakeSound();
    std::cout << "================================" << std::endl;

    Animal* zoo[4];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Cow();
    zoo[3] = new Parrot();

    for (int i = 0; i < 4; i++)
    {
        std::cout << "Animal #" << i + 1  << std::endl;
        zoo[i]->MakeSound();
        zoo[i]->AskForFood();
        zoo[i]->Move();
        std::cout << "================================" << std::endl;
    }

   
    for (int i = 0; i < 4; i++)
    {
        delete zoo[i];
    }

    return 0;
}