#include <iostream>
#include "my_class.h"

my_class::my_class() : field(1), my_string("great")
{
    std::cout << field << std::endl;
    std::cout << my_string << std::endl;
    field = 0;
    my_string = "hello";
}

my_class::my_class(int value, const std::string& str) : field (value), my_string(str)
{ 
}

my_class::~my_class() = default;

my_class::my_class(const my_class &other)
{
    field = other.field;
    my_string = other.my_string;
}

my_class::my_class(my_class &&other)
{
    field = std::move(other.field);
    my_string = std::move(other.my_string);
}

my_class& my_class::operator=(const my_class &other)
{
    field = other.field;
    my_string = other.my_string;
    return *this;
    
}

my_class &my_class::operator=(my_class &&other)
{
    field = std::move(other.field);
    my_string = std::move(other.my_string);
    return *this;
}

void my_class::print()
{
    std::cout << my_string << ' ' << field << std::endl;
}

void derivative_class::print()
{
    std::cout << "derivative" << std::endl;
}