// Polymorphic Objects - Dynamic Cast
// Cube.cpp

#include <iostream>
#include "Cube.h"

Cube::Cube(double l) : len(l) { }

void Cube::display() const
{
    std::cout << "length = " << len << std::endl;
}

double Cube::volume() const
{
    return len * len * len;
}

bool Cube::operator==(const Shape& s) const
{
    const Cube* c = dynamic_cast<const Cube*>(&s);
    return c ? len == c->len : false;
}