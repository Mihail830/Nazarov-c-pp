#include "vec1.h"
#include <stdexcept>

Vector1::Vector1(int size) : size_(size), data_(nullptr)
{
    if (size < 0)
    {
        throw std::invalid_argument("Vector size < 0");
    }
    else
    {
        data_ = new double[size] {};
    }
}

Vector1::~Vector1()
{
    delete[] data_;
}

int Vector1::size() const
{
    return size_;
}

double Vector1::get(int n) const
{
    if (n < 0 || n >= size_)
    {
        throw std::out_of_range("Vector index out of range");
    }
    return data_[n];
}

void Vector1::set(int n, double v)
{
    if (n < 0 || n >= size_)
    {
        throw std::out_of_range("Vector index out of range");
    }
    data_[n] = v;
}
