#ifndef DOGFACTORY_H
#define CDOGFACTORY_H
#define DOG_H
#include"Factory.h"
class DogFactory:public Factory
{
public:
    DogFactory();
    Animal* createAnimal() override;
    virtual ~DogFactory();
};
#endif