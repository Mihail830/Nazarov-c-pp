#include <iostream>
#include "vec2.h"


void print(const Vector2& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " | ";
    }
}


int main()
{

    // Конструктор размера
    
    Vector2 v(5);
    std::cout << "Size = 5  " << "vector = ";
    print(v); 
    
    // Конструктор из списка инициализации
    
    Vector2 vec = {2.71, 3.14, 5.5};
    std::cout << std::endl << ".............." << std::endl;
    std::cout << "Size = " << vec.size() << "  vector = ";
    print(vec); 

    // Копирующий конструктор, копия не трогает оригинал

    Vector2 copy = vec;
    copy[0] = 77.7;
    std::cout << std::endl << "............." << std::endl;
    std::cout << "Original vector = ";
    print(vec);
    std::cout << std::endl << "Copy vector = ";
    print(copy);
    
    // Перемещающий конструктор

    Vector2 a {7.5, 15.5, 33.2};
    std::cout << std::endl << "............." << std::endl;
    std::cout << "Size a = " << a.size() << std::endl;
    Vector2 b = std::move(a);
    std::cout << "New size a = " << a.size() << std::endl;
    std::cout << "Size b = " << b.size() << std::endl;

    // Копирующее присваивание

    Vector2 v1 {1.1, 2.2, 3.3};
    Vector2 v2 {9.9, 8.8};
    v2 = v1;
    std::cout << "............." << std::endl;
    std::cout << "v2 = v1 --> size v2 = " << v2.size() << std::endl;
    std::cout << "Vector v2 = ";
    print(v2);

    // Перемещающее присваивание

    Vector2 vec1 {5.5, 6.6, 7.7};
    Vector2 vec2{0};
    std::cout << std::endl << "............." << std::endl;
    std::cout << "Size vec1 = " << vec1.size() << "  Size vec2 = " << vec2.size() << std::endl;
    vec2 = std::move(vec1);
    std::cout << "New size vec1 = " << vec1.size() << "  New size vec2 = " << vec2.size() << std::endl;
    std::cout << "Vector vec2 = ";
    print(vec2);
 
    return 0;
}