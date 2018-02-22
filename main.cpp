//using namespace std;

#include <iostream>
#include "vector.h"
#include "integrators.h"
#include <sstream>
#include <string>
#include <cmath>

const double G = 6.67408e-11; // m3 kg-1 s-2
const int n = 2; // Number of bodies to propagate
const double stepSize = 50; // s

class Body
{
    public:
    Body();
    Body(Vector, double);
    Body(Vector, Vector, double);

    Vector position;
    Vector velocity;
    Vector extForces;
    double mass;

};

Body::Body()
{
    velocity = Vector(0.0, 0.0, 0.0);
    extForces = Vector(0.0, 0.0, 0.0);
}

Body::Body(Vector initPos, double initMass)
{
    position = initPos;
    velocity = Vector(0.0, 0.0, 0.0);
    extForces = Vector(0.0, 0.0, 0.0);
    mass = initMass;
}

Body::Body(Vector initPos, Vector initVel, double initMass)
{
    position = initPos;
    velocity = initVel;
    extForces = Vector(0.0, 0.0, 0.0);
    mass = initMass;
}

int main()
{
    Body bodies[n];
    bodies[0] = Body(Vector(0.0, 0.0, 0.0), 1e24);
    bodies[1] = Body(Vector(1e6, 2.0, 0.0), 50);
    // Loop through all bodies in the simulation
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // Don't calculate forces if exerting body j == influenced body i
            if(j == i)
            {
                continue;
            }
            // Determine relative vector r(i,j) between bodies i and j
            Vector r = bodies[j].position - bodies[i].position;
            bodies[i].extForces += r * ((G * bodies[j].mass)/std::pow(r.getLength(), 3));
            std::cout << i << ", " << j << ": "<< r.getLength() << "\n";
        }
        std::cout << bodies[i].extForces.getLength() << "\n";
    }
    return 0;
}
