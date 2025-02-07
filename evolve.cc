#include "evolve.h"
#include <math.h>

evolve& evolve::setSystem(solarSystem *s)
{
  _bodies = s->getComponents();
  return *this;
}

evolve& evolve::setDt(double dt)
{
  _dt = dt;
  return *this;
}

evolve& evolve::setG(double G)
{
  _G = G;
  return *this;
}


myVector evolve::calculateForce(body *corpo)
{
  myVector F(3);
  F = 0.;
  std::list<body *>::iterator i = _bodies.begin();
  std::list<body *>::iterator e = _bodies.end();
  while (i != e)
    {
      if ((*i) != corpo)
	{
	  myVector dist;
	  dist = corpo->getPosition() - (*i)->getPosition();
	  F += dist*(-_G*(corpo->getMass())*((*i)->getMass())/(pow(dist.norm(),3)));
	}
      i++;
    }
  return F;
}

void evolve::evolution()
{
  std::list<body *>::iterator i = _bodies.begin();
  std::list<body *>::iterator e = _bodies.end();
  while (i != e)
    {
      (*i)->move(calculateForce(*i), _dt);
      i++;
    }
}
