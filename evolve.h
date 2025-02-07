#ifndef _EVOLVE_H
#define _EVOLVE_H

#include "solarSystem.h"
#include "myVector.h"
#include "body.h"
#include <list>

class evolve
{
private:
  std::list<body *> _bodies;
  double _dt;
  double _G;
public:
  evolve& setSystem(solarSystem *s);
  evolve& setDt(double dt);
  evolve& setG(double G);
  myVector calculateForce(body *corpo);
  void evolution();
  
};

#endif
