//
// Created by elmar on 3-3-18.
//

#ifndef CPPTEST_FORWARDEULER_H
#define CPPTEST_FORWARDEULER_H

#include "integrator.h"

namespace simulator
{
    class ForwardEulerIntegrator:Integrator
    {
    public:
        void ForwardEulerIntegrator(double timeStep, double startTime, double endTime, int type);

    };
}

#endif //CPPTEST_FORWARDEULER_H
