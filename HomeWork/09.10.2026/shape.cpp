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

Circle::Circle(double radius) : Shape("circle"), radius_(radius)
{
    if (radius <= 0)
    {
        throw std::invalid_argument("Circle radius must be > 0 ");
    }
}

double Circle::area() const
{
    return pi * radius_ * radius_;
}

double Circle::perimeter() const
{
    return radius_ * 2.0 * pi;
}

Triangle::Triangle(double a, double b, double c) : Shape("triangle"), a_(a), b_(b), c_(c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        throw std::invalid_argument("Triangle sides must be > 0 ");
    }

    if(a + b <= c || a + c <= b || b + c <= a)
    {
        throw std::invalid_argument("Triangle doesn't exist ");
    }
}

double Triangle::area() const
{
    double per = perimeter() / 2.0;
    return std::sqrt(per * (per - a_) * (per - b_) * (per - c_));
}

double Triangle::perimeter() const
{
    return a_ + b_ + c_;
}

bool operator==(const Shape &lhs, const Shape &rhs)
{
    return std::abs(lhs.area() - rhs.area()) < 1e-6;
}

bool operator^(const Shape &lhs, const Shape &rhs)
{
    return std::abs(lhs.perimeter() - rhs.perimeter()) < 1e-6;
}

std::ostream &operator<<(std::ostream &os, const Shape &shape)
{
    os << "Name: " << shape.getName() << std::endl
       << "Area: " << shape.area() << std::endl
       << "Perimeter: " << shape.perimeter() << std::endl;
    
       return os;
}
