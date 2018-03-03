#include "integrator.h"

namespace simulator
{
    Integrator::Integrator(double timeStep, int type)
    {
        this->timeStep = timeStep;
        // Set integrator type; consider making integrator class virtual
    }

    void Integrator::performTimeStep()
    {

    }
}
