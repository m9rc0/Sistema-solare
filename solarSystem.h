#ifndef _SOLARSYSTEM_H
#define _SOLARSYSTEM_H

#include "subSystem.h"

class solarSystem : public subSystem
{
private:
  std::list<subSystem *> _components; 
public:
  solarSystem();
  solarSystem& add(subSystem *s, const myVector &x, const myVector &v);
  solarSystem& setPosition(const myVector &x);
  solarSystem& setVelocity(const myVector &v);
  std::list<body *> getComponents();
  myVector getAngularMomentum();
};

#endif
