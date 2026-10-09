#pragma once
#include <string>
#include <iostream>

const double pi = 3.1415926535;

class Shape
{
private:
    std::string name_;

public:
    const std::string& getName() const;
    virtual double area() const;
    virtual double perimeter() const;

    Shape() = default;
    Shape(const std::string& name);
    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;
    Shape& operator = (const Shape& other);
    Shape& operator = (Shape&& oyher) noexcept;
    virtual ~Shape() = default; 
};

class Rectangular: public Shape
{
protected:
    double width_;
    double length_;

public:
    Rectangular(double wight, double length);
    virtual double area() const override;
    virtual double perimeter() const override;
 };

 