#include "vec2.h"
#include <algorithm>
#include <stdexcept>

Vector2::Vector2(int size) : size_(size), data_(nullptr)
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

Vector2::Vector2(std::initializer_list<double> lst) : size_(lst.size()), data_(new double[lst.size()]{})
{
    std::copy(lst.begin(), lst.end(), data_);
}

Vector2::Vector2(const Vector2 &other) : size_(other.size_), data_(new double[other.size_]{})
{
    if (other.size_ > 0)
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }
}

Vector2::Vector2(Vector2 &&other) noexcept : size_(other.size_), data_(other.data_)
{
    other.size_ = 0;
    other.data_ = nullptr;
}

Vector2::~Vector2()
{
    delete[] data_;
}

Vector2 &Vector2::operator=(const Vector2 &other)
{
    if (this == &other)
    {
    return *this;
    }
    
    double* p = new double[other.size_]{};

    if (other.size_ > 0)
    {
        std::copy(other.data_, other.data_ + other.size_, p);
    }

    delete[] data_;
    data_ = p;
    size_ = other.size_;
    return *this;
}

Vector2 &Vector2::operator=(Vector2 &&other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] data_;
    data_ = other.data_;
    size_ = other.size_;

    other.data_ = nullptr;
    other.size_ = 0;
    return *this;
    
}

int Vector2::size() const
{
    return size_;
}

double &Vector2::operator[](int n)
{
    return data_[n];
}

const double &Vector2::operator[](int n) const
{
    return data_[n];
}
