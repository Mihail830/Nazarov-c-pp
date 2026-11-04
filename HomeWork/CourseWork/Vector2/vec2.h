#pragma once
#include <algorithm>

class Vector2
{
private:
    int size_;
    double* data_;

public:
    explicit Vector2(int size);
    Vector2(std::initializer_list<double> lst);
    Vector2(const Vector2& other);
    Vector2(Vector2&& other) noexcept;
    ~Vector2();

    Vector2& operator=(const Vector2& other);
    Vector2& operator=(Vector2&& other) noexcept;

    int size() const;

    double& operator[](int n);
    const double& operator[](int n) const;
};