// Polymorphic Objects - Dynamic Cast
// Cube.h

#include "Shape.h"

class Cube : public Shape
{
    double len;
public:
    Cube(double len);
    void display() const;
    double volume() const;
    bool operator==(const Shape&) const;
};