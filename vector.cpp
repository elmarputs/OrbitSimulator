#include "vector.h"
#include <cmath>

Vector::Vector()
{
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(double a, double b, double c)
{
    x = a;
    y = b;
    z = c;
    length = getLength();
}

double Vector::getLength()
{
    return std::sqrt(x*x + y*y + z*z);
}

Vector Vector::operator+=(Vector v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

Vector Vector::operator+(Vector v)
{
    return Vector(v.x + this->x, v.y + this->y, v.z + this->z);
}

Vector Vector::operator-(Vector v)
{
    return Vector(v.x - this->x, v.y - this->y, v.z - this->z);
}

Vector Vector::operator*(double c)
{
    return Vector(c*this->x, c*this->y, c*this->z);
}
