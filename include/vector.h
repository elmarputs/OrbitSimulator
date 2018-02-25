#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
    Vector();
    Vector(double, double, double);
    double getLength();
    void operator+=(Vector);
    Vector operator+(Vector);
    Vector operator-(Vector);
    Vector operator*(double);

    double x;
    double y;
    double z;
    double length;
};

#endif // VECTOR_H
