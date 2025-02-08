#ifndef _INTEGRATOR_H
#define _INTEGRATOR_H

#include "solarSystem.h"
#include "body.h"
#include "myVector.h"
#include <list>


class integrator
{
protected:
  std::list<body *> _bodies;
  double _G;
  double _dt;
public:
  myVector calculateAcceleration(body *corpo);
  integrator& setSystem(solarSystem *s);
  integrator& setDt(double dt);
  integrator& setG(double G);
  virtual integrator& nextStep(body *corpo) = 0;
};

class eulerIntegrator : public integrator
{
public:
  eulerIntegrator& nextStep(body *corpo);
};

class RK2 : public integrator
{
public:
  RK2& nextStep(body *corpo);
};

#endif
