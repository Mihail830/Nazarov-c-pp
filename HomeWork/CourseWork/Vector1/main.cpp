#include "vec1.h"
#include <iostream>

int main()
{
    Vector1 vec(4);

    // Размер вектора
    std::cout << "Size vector = " << vec.size() << std::endl;
    
    // Запись значений через set()
    vec.set(0, 1.5);
    vec.set(1, 5.5);
    vec.set(2, 4.4);

    std::cout << "Elements of vector: " << std::endl;
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec.get(i) << std::endl;
    }

    // Чтение значения через get()
    std::cout << "===============" << std::endl;
    std::cout << "Element two = " << vec.get(1) << std::endl;

    // Изменение элемента
    std::cout << "=================" << std::endl;
    std::cout << "Element one = " << vec.get(0) << std::endl;
    vec.set(0, 99.9);
    std::cout << "New value = " << vec.get(0);
    
    


    return 0;
}