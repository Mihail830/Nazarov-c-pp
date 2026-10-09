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
