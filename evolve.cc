#include "evolve.h"

evolve& evolve::setAlgorithm(integrator *I)
{
  _I = I;
  return *this;
}

evolve& evolve::setSystem(solarSystem *s)
{
  _bodies = s->getComponents();
  _I->setSystem(s);
  return *this;
}

evolve& evolve::setDt(double dt)
{
  _I->setDt(dt);
  return *this;
}

evolve& evolve::setG(double G)
{
  _I->setG(G);
  return *this;
}

evolve& evolve::evolution()
{
  std::list<body *>::iterator i = _bodies.begin();
  std::list<body *>::iterator e = _bodies.end();

  while (i != e)
    {
      (*i)->move(_I);
      i++;
    }
  return *this;
}


