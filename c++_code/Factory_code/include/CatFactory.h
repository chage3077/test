#ifndef CATFACTORY_H
#define CATFACTORY_H
#define CAT_H
#include"Factory.h"
class CatFactory:public Factory
{
public:
    CatFactory();
    Animal* createAnimal() override;
    virtual ~CatFactory();
};
#endif