//using namespace std;

#include <iostream>
#include "vector.h"
#include "integrators.h"
#include <string>
#include <cmath>
#include <fstream>

const double G = 6.67408e-11; // m3 kg-1 s-2
const int n = 2; // Number of bodies to propagate
const double propagationTime = 6000.0; // s
const double stepSize = 30.0; // s

class Body
{
    public:
    Body();
    Body(Vector, double);
    Body(Vector, Vector, double);

    Vector position;
    Vector velocity;
    Vector accelerations;
    Vector positions[];
    double mass;

};

Body::Body()
{
    velocity = Vector(0.0, 0.0, 0.0);
    accelerations = Vector(0.0, 0.0, 0.0);
}

Body::Body(Vector initPos, double initMass)
{
    position = initPos;
    velocity = Vector(0.0, 0.0, 0.0);
    accelerations = Vector(0.0, 0.0, 0.0);
    mass = initMass;
}

Body::Body(Vector initPos, Vector initVel, double initMass)
{
    position = initPos;
    velocity = initVel;
    accelerations = Vector(0.0, 0.0, 0.0);
    mass = initMass;
}

void outputToFile(Vector data[])
{


}

int main()
{
    Body bodies[n];
    bodies[0] = Body(Vector(0.0, 0.0, 0.0), 5.98e24);
    bodies[1] = Body(Vector(6.78e6, 0.0, 0.0), Vector(0.0, 7672.4, 0.0), 500);
    Vector positions[int(propagationTime/stepSize)];
    int counter = 0;
    for(double t = 0; t < propagationTime; t += stepSize)
    {
        //std::cout << "Radius: " << bodies[1].position.getLength() << "\n";
        //std::cout << bodies[1].position.x/1.0e3 << ", " << bodies[1].position.y/1.0e3 << "\n";
        // Loop through all bodies in the simulation and calculate accelerations at t
        for(int i = 0; i < n; i++)
        {
            Vector drdx = Vector(0.0, 0.0, 0.0);
            for(int j = 0; j < n; j++)
            {
                // Implementation of RK4 integrator with Cartesian EoMs
                // Don't calculate forces if exerting body j == influenced body i
                if(j == i)
                {
                    continue;
                }
                double mu_j = G*bodies[j].mass;

                // Determine relative vector r(i,j) between bodies i and j
                Vector r = bodies[j].position - bodies[i].position;
                // Calculate begin point
                Vector k1 = r * (-mu_j/std::pow(r.getLength(), 3));

                // Extrapolate position of body i and update relative vector
                Vector tempVel1 = bodies[i].velocity + k1 * (stepSize/1.0);
                Vector tempPos = bodies[i].position + tempVel1 * (stepSize/1.0);
                r = bodies[j].position - tempPos;
                // Calculate midpoint 1
                Vector k2 = r * (-mu_j/std::pow(r.getLength(), 3));

                // Extrapolate position of body i and update relative vector
                Vector tempVel2 = tempVel1 + k2 * (stepSize/2.0);
                tempPos = tempPos + tempVel2 * (stepSize/2.0);
                r = bodies[j].position - tempPos;
                // Calculate midpoint 2
                Vector k3 = r * (-mu_j/std::pow(r.getLength(), 3));

                // Extrapolate position of body i and update relative vector
                Vector tempVel3 = tempVel2 + k3 * stepSize;
                tempPos = tempPos + tempVel3 * stepSize;
                r = bodies[j].position - tempPos;
                // Calculate endpoint
                Vector k4 = r * (-mu_j/std::pow(r.getLength(), 3));

                bodies[i].accelerations += k1;//(k1 + k2*2 + k3*2 + k4) * (1.0/6.0);
                drdx += (bodies[i].velocity + tempVel1*2 + tempVel2*2 + tempVel3) * (1.0/6.0);
            }

            // Update velocity and position vectors
            bodies[i].velocity += bodies[i].accelerations * stepSize;
            bodies[i].position += drdx * stepSize;
            // Reset acceration vector
            bodies[i].accelerations = Vector(0.0, 0.0, 0.0);

            positions[counter] = bodies[i].position;
        }

        counter++;
    }

    //std::cout << bodies[1].positions[30].getLength() << "\n";
    std::ofstream file;
    file.open("orbit.dat");

    //if(!file.is_open())
    //{
    //    std::cout << "Error while opening file!" << "\n";
    //}

    //std::cout << sizeof(positions) << "\n";

    for(int p = 0; p < int(propagationTime/stepSize); p++)
    {
        file << positions[p].x << " " << positions[p].y << "\n";
    }

    //file << "Hello world!\n";

    file.close();

    return 0;
}
