#include "vec1.h"

Vector1::Vector1(int size) : size_(size), data_(new double[size] {})
{
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
    return data_[n];
}

void Vector1::set(int n, double v)
{
    data_[n] = v;
}
