#pragma once

class Vector1
{
private:
    int size_;
    double* data_;

public:
    Vector1(int size);
    ~Vector1();

    int size() const;
    double get(int n) const;
    void set(int n, double v);
};