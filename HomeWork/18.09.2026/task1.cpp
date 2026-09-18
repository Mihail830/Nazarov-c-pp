#include <iostream>
#include <string>
#include <vector>

int main() 
{ 
    int a = 0;
    std::vector<std::string> months 
    {
        "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"
    };
    std::cout << "Print number months: " << std::endl;
    std::cin >> a;
    if (a >= 1 && a <= 12)
    {
        std::cout << months[a - 1];
    }
    else
    {
        std::cout << "Warning! 1 < a < 12" << std::endl;
    }

    return 0;
}