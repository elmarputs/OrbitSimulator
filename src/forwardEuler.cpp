//
// Created by elmar on 3-3-18.
//

#include "forwardEuler.h"

namespace simulator
{
    void ForwardEulerIntegrator::ForwardEulerIntegrator(double timeStep, double startTime, double endTime, int type)
    {
        this->timeStep = timeStep;
        this->startTime = startTime;
        this->endTime = endTime;
    }


}