#ifndef INTEGRATORS_H
#define INTEGRATORS_H

namespace simulator
{
    class Integrator
    {
    protected:
        double timeStep;
        double startTime;
        double endTime;
    public:
        void Integrator(double timeStep, int type);
        virtual void performTimeStep();
        virtual void adaptTimeStep();
    };
}

#endif // INTEGRATORS_H
