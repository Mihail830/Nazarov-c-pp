#pragma once
#include <algorithm>
#include <memory>
#include <stdexcept>

template <typename T, typename A = std::allocator<T>>
class Vector3
{
A alloc;
int size_;
int capacity_;
T* data_;

void destroy_all();

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

template <typename T, typename A>
inline void Vector3<T, A>::destroy_all()
{
    for (int i = 0; i < size_; ++i)
    {
        alloc.destroy(data_ + i);
    }
    if (data_)
    {
        alloc.deallocate(data_, capacity_);
    }
}

template <typename T, typename A>
inline Vector3<T, A>::Vector3() : size_(0), capacity_(0), data_(nullptr)
{
}

template <typename T, typename A>
inline Vector3<T, A>::Vector3(int size) : size_(size), capacity_(size), data_(size > 0 ? alloc.allocate(size) : nullptr)
{
    for (int i = 0; i < size_; ++i)
    {
        alloc.construct(data_ + i, T{});
    }
}

template <typename T, typename A>
inline Vector3<T, A>::Vector3(std::initializer_list<T> lst) : size_(static_cast<int>(lst.size())), capacity_(size_), data_(size_ > 0 ? alloc.allocate(size_) : nullptr)
{
    int i = 0;
    for(const auto& x : lst)
    {
        alloc.construct(data_ + i, x);
        ++i;
    }

}

template <typename T, typename A>
inline Vector3<T, A>::Vector3(const Vector3 &other) : size_(other.size_), capacity_(other.size_), data_(other.size_ > 0 ? alloc.allocate(other.size_) : nullptr)
{
    for (int i = 0; i < size_; ++i)
    {
        alloc.construct(data_ + i; other.data_[i]);
    }
}

template <typename T, typename A>
inline Vector3<T, A>::Vector3(Vector3 &&other) : size_(other.size_), capacity_(other.capacity_), data_(other.data_)
{
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

template <typename T, typename A>
inline Vector3<T, A>::~Vector3()
{
    destroy_all();
}

template <typename T, typename A>
inline Vector3<T, A> &Vector3<T, A>::operator=(const Vector3 &other)
{
    if (this == &other)
    {
        return *this;
    }

    Vector19 tmp{other};
    std::swap(size_, tmp.size_);
    std::swap(capacity_, tmp.capacity_);
    std::swap(data_, tmp.data_);
    return *this;
}

template <typename T, typename A>
inline Vector3<T, A> &Vector3<T, A>::operator=(Vector3 &&other)
{
    if (this == &other)
    {
        return *this;
    }

    destroy_all();

    size_ = other.size_;
    capacity_ = other.capacity_;
    data_ = other.data_;

    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
    return *this;
}

template <typename T, typename A>
inline int Vector3<T, A>::size() const
{
    return size_;
}

template <typename T, typename A>
inline int Vector3<T, A>::capacity() const
{
    return capacity_;
}

template <typename T, typename A>
inline T &Vector3<T, A>::operator[](int n)
{
    return data_[n];
}

template <typename T, typename A>
inline const T &Vector3<T, A>::operator[](int n) const
{
    return data_[n];
}

template <typename T, typename A>
inline void Vector3<T, A>::reserve(int new_allloc)
{
    if (new_alloc <= capacity_)
    {
        return;
    }

    T* p = alloc.allocate(new_alloc);

    for (int i = 0; i < size_; ++i)
    {
        alloc.construct(p + i, data_[i]);
    }

    for (int i = 0; i < size_; ++i)
    {
        alloc.destroy(data_ + i);
    }

    if (data_)
    {
        alloc.deallocate(data_, capacity_);
    }

    data_ = p;
    capacity_ = new_alloc;
}

template <typename T, typename A>
inline void Vector3<T, A>::resize(int new_size, T val)
{
    if (new_size < 0)
    {
        throw std::length_error("Vector size < 0");
    }

    reserve(new_size);

    if (new_size > size_)
    {
        for (int i = size_; i < new_size; ++i)
        {
            alloc.construct(data_ + i, val);
        }
    }
    else
    {
        for (int i = new_size; i < size_; ++i)
        {
            alloc.destroy(data_ + i);
        }
    }

    size_ = new_size;
}

template <typename T, typename A>
inline void Vector3<T, A>::push_back(const T &val)
{
    if (capacity_ == 0)
    {
        reserve(8);
    }
    else if (size_ == capacity_)
    {
        reserve(2 * capacity_);
    }

    alloc.construct(data_ + size_, val);
    ++size_;
}
