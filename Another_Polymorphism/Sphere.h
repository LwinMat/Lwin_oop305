// Polymorphic Objects - Dynamic Cast
// Sphere.h

#include "Shape.h"

class Sphere : public Shape
{
    double rad;
public:
    Sphere(double);
    void display() const;
    double volume() const;
    bool operator==(const Shape&) const;
};