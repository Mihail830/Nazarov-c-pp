
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
srand(static_cast<unsigned int>(time(0)));
int a = rand() % 100 + 1;
int b = 0;

std::cout << "Ygadaite chislo ot 1 do 100" << std::endl;

while (true)
{
    std::cout << "Tvoi variant: " << std::endl;
    std::cin >> b;
    if (a == b)
    {
        std::cout << "Ti pobedil!" << std::endl;
        break;
    }
    else if (b < a)
    {
        std::cout << "Greater!" << std::endl;
    }
    else
    {
        std::cout << "Less!" << std::endl;
    }
}

return 0;
}