// Polymorphic Objects - Dynamic Cast
// Sphere.cpp

#include <iostream>
#include "Sphere.h"

Sphere::Sphere(double r) : rad(r) { }

void Sphere::display() const
{
    std::cout << "radius = " << rad << std::endl;
}

double Sphere::volume() const
{
    return 4.18879 * rad * rad * rad;
}

bool Sphere::operator==(const Shape& s) const
{
    const Sphere* c = dynamic_cast<const Sphere*>(&s);
    return c ? rad == c->rad : false;
}