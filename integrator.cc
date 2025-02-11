#include "integrator.h"
#include <math.h>

integrator& integrator::setSystem(solarSystem *s)
{
  _bodies = s->getComponents();
  return *this;
}

integrator& integrator::setDt(double dt)
{
  _dt = dt;
  return *this;
}

integrator& integrator::setG(double G)
{
  _G = G;
  return *this;
}

myVector integrator::calculateAcceleration(body *corpo)
{
  myVector F(3);
  F = 0.;
  std::list<body *>::iterator i = _bodies.begin();
  std::list<body *>::iterator e = _bodies.end();
  while (i != e)
    {
      if ((*i)->getName() != corpo->getName())
	{
	  myVector dist;
	  dist = corpo->getPosition() - (*i)->getPosition();
	  F += dist*(-_G*((*i)->getMass())/(pow(dist.norm(),3)));
	}
      i++;
    }
  return F;
}


eulerIntegrator& eulerIntegrator::nextStep(body *corpo)
{
  corpo->setVelocity(calculateAcceleration(corpo)*_dt);
  corpo->setPosition((corpo->getVelocity())*_dt);
  return *this;
}


RK2& RK2::nextStep(body *corpo)
{
  body temp;
  temp = *corpo;
  
  myVector dx(3), dv(3);
  dx = corpo->getVelocity()*_dt;
  dv = calculateAcceleration(corpo)*_dt;

  temp.setPosition(dx*0.5);
  temp.setVelocity(dv*0.5);
  corpo->setPosition(temp.getVelocity()*_dt);
  corpo->setVelocity(calculateAcceleration(&temp)*_dt);
  
  return *this;
}
