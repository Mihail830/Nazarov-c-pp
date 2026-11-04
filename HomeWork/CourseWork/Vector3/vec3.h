#pragma once
#include <algorithm>
#include <memory>
#include <stdexcept>

template <typename T, typename A = std::allocator<T>>
class Vector3
{
std::allocator<T> alloc;
int size_;
int capacity_;
T* data_;

public:
    // Конструкторы, деструктор
    Vector3();
    explicit Vector3(int size);
    Vector3(std::initializer_list<T> lst);
    Vector3(const Vector3& other);
    Vector3(Vector3&& other);
    ~Vector3();

    // Присваивание
    Vector3& operator=(const Vector3& other);
    Vector3& operator=(Vector3&& other);

    // Размер, емкость
    int size() const;
    int capacity() const;

    // Индексация
    T& operator[](int n);
    const T& operator[](int n) const;

    // Изменение размера
    void reserve(int new_allloc);
    void resize(int new_size, T val = T{});
    void push_back(const T& val);
};

