#include "solarSystem.h"

solarSystem::solarSystem() {
  _components = std::list<subSystem *>();
}


solarSystem& solarSystem::add(subSystem *s, const myVector &x, const myVector &v)
{
  s->setPosition(x);
  s->setVelocity(v);
  _components.push_back(s);
  // see if this line needs to be removed
  _components.unique();
  return *this;
}

/********************/

solarSystem& solarSystem::setPosition(const myVector &x)
{
  // updates recursively the position of all bodies
  std::list<subSystem *>::iterator i = _components.begin();
  std::list<subSystem *>::iterator e = _components.end();
  while (i != e)
    {
      (*i)->setPosition(x);
      i++;
    }
  return *this;
}

/********************/

solarSystem& solarSystem::setVelocity(const myVector &v)
{
  // updates recursively the position of all bodies
  std::list<subSystem *>::iterator i = _components.begin();
  std::list<subSystem *>::iterator e = _components.end();
  while (i != e)
    {
      (*i)->setVelocity(v);
      i++;
    }
  return *this;
}

/********************/

std::list<body *> solarSystem::getComponents()
{
  // recursively creates a list of bodies
  std::list<body *> l;
  std::list<subSystem *>::iterator i = _components.begin();
  std::list<subSystem *>::iterator e = _components.end();
  // maybe better to do with do-while but think about it 
  while (i != e)
    {
      std::list<body *> ll = (*i)->getComponents();
      l.merge(ll);
      i++;
    }
  return l;
}

/********************/

myVector solarSystem::getAngularMomentum()
{
  myVector L(3);
  L = 0.;
  // calculates recursively the total angular momentum of the system
  std::list<subSystem *>::iterator i = _components.begin();
  std::list<subSystem *>::iterator e = _components.end();
  while (i != e)
    {
      L += (*i)->getAngularMomentum();
      i++;
    }
  return L;
}

/********************/
