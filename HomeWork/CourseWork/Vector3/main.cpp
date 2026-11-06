#include "vec3.h"
#include <iostream>


template <typename T>
void print(const Vector3<T>& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " | ";
    }
}


int main()
{
    // Конструктор по умолчанию
    Vector3<int> vec;
    std::cout << "Size vec = " << vec.size() << " capacity = " << vec.capacity() << std::endl;

    // Конструктор с размером
    Vector3<int> v(5);
    std::cout << "Size = " << v.size() << " capacity = " << v.capacity() << " vector = ";
    print(v); 
    std::cout << std::endl << ".............." << std::endl;

    // Конструктор из списка инициализации
    Vector3<int> a {1, 2, 3, 4, 5};
    std::cout << "Size vec = " << a.size() << " capacity = " << a.capacity() << " vector = ";
    print(a); 
    std::cout << std::endl << ".............." << std::endl;

    // Копирующий конструктор, копия не трогает оригинал
    Vector3<int> vec1 {10, 11, 12, 13};
    Vector3<int> vec2 = vec1;
    vec2[0] = 99;
    std::cout << "Size vec1 = " << vec1.size() << " capacity vec1 = " << vec1.capacity() << " vec1 = ";
    print(vec1);
    std::cout << std::endl << "Coping: " << std::endl;
    std::cout << "Size vec2 = " << vec2.size() << " capacity vec2 = " << vec2.capacity() << " vec2 = ";
    print(vec2);

    // Перемещающий конструктор
    std::cout << std::endl << ".............." << std::endl;
    Vector3<int> v1 {20, 21, 22, 23};
    std::cout << "Size = " << v1.size() << " capacity = " << v1.capacity() << " vector = ";
    print(v1);
    Vector3<int> v2 = std::move(v1);
    std::cout << std::endl << "Moved: " << std::endl;
    std::cout << "Size = " << v2.size() << " capacity = " << v2.capacity() << " vector = ";
    print(v2);
    
    // Копирующее присваивание
    std::cout << std::endl << ".............." << std::endl;
    Vector3<int> vbeg {52, 67, 99};
    Vector3<int> vend;
    vend = vbeg;
    std::cout << " Begining: size = " << vbeg.size() << " capacity = " << vbeg.capacity() << " vector = ";
    print(vbeg);
    std::cout << std::endl << " End: size = " << vend.size() << " capacity = " << vend.capacity() << " vector = ";
    print(vend);

    // Перемещающее присваивание
    std::cout << std::endl << ".............." << std::endl;
    Vector3<int> a1 {33, 44, 55, 66};
    Vector3<int> b1;
    b1 = std::move(a1);
    std::cout << " Size a = " << a1.size() << " capacity a = " << a1.capacity() << " vector a = ";
    print(a1);
    std::cout << std::endl << " Size b = " << b1.size() << " capacity b = " << b1.capacity() << " vector b = ";
    print(b1);

    // puch_back
    std::cout << std::endl << ".............." << std::endl;
    Vector3<int> a11;
    for (int i = 0; i < 5; ++i)
    {
        a11.push_back(i * 10);
    }
    std::cout << "Vector = ";
    print(a11);

    // reserve
    std::cout << std::endl << ".............." << std::endl;
    Vector3<int> aa;
    aa.reserve(10);
    std::cout << "Capacity = " << aa.capacity() << std::endl;

    // resize
    std::cout << std::endl << ".............." << std::endl;
    Vector3<int> bb {22, 23, 24};
    std::cout << "Vector = ";
    print(bb);
    bb.resize(6, 99);
    std::cout << std::endl << "Vector 2 = ";
    print(bb);

    // string
    std::cout << std::endl << ".............." << std::endl;
    Vector3<std::string> vs {"one", "two"};
    std::cout << "String vector = ";
    print(vs);
    vs.push_back("three");
    std::cout << std::endl << "String vector 2 = ";
    print(vs);

     // pop_back
     std::cout << std::endl << ".............." << std::endl;
     Vector3<int> test {1, 2, 3};
     std::cout << "Test vector = ";
     print(test);
     test.pop_back();
     std::cout << std::endl << "Vector (pop_back) = ";
     print(test);

    return 0;
}