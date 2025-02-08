#ifndef _EVOLVE_H
#define _EVOLVE_H

#include "solarSystem.h"
#include "myVector.h"
#include "body.h"
#include "integrator.h"
#include <list>

class evolve
{
private:
  std::list<body *> _bodies;
  integrator *_I;
public:
  evolve& setAlgorithm(integrator *I);
  evolve& setSystem(solarSystem *s);
  evolve& setDt(double dt);
  evolve& setG(double G);
  evolve& evolution();
  
};

#endif
