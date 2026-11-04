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
    Vector2 vec = {2.71, 3.14, 5.5};
    std::cout << "Vector = ";
    print(vec);


    



    return 0;
}