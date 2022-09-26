#ifndef SHAPE_H
#define SHAPE_H
// Polymorphic Objects - Dynamic Cast
// Shape.h

class Shape
{
public:
    virtual double volume() const = 0;
    virtual void display() const = 0;
    virtual bool operator==(const Shape&) const = 0;
};
#endif