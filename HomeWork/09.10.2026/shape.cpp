#include <cmath>
#include "shape.h"

Shape::Shape(const std::string &name) : name_(name)
{
}

Shape::Shape(const Shape &other) : name_(other.name_)
{
}

Shape::Shape(Shape &&other) noexcept : name_(std::move(other.name_))
{
}

Shape &Shape::operator=(const Shape &other)
{
    if (this != &other)
    {
        name_ = other.name_;
    }
    return *this;
}

Shape &Shape::operator=(Shape &&other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
    }
    return *this;
}

Shape::~Shape() {}

const std::string& Shape::getName() const
{
    return name_;
}

double Shape::area() const
{
    return 0.0;
}

double Shape::perimeter() const
{
    return 0.0;
}

Rectangular::Rectangular(double width, double length) : Shape("rectangular"), width_(width), length_(length)
{
    if (width <= 0 || length <= 0)
    {
        throw std::invalid_argument("Rectangular sides must be > 0 ");
    }
}

double Rectangular::area() const
{
    return width_ * length_;
}

double Rectangular::perimeter() const
{
    return (width_ + length_) * 2.0;
}

Squar::Squar(double side) : Rectangular(side, side)
{
    name_ = "squar";
}


