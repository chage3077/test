#include"Dog.h"
#include "DogFactory.h"
DogFactory::DogFactory()
{
}
Animal *DogFactory::createAnimal()
{
    return new Dog;
}

DogFactory::~DogFactory()
{
    std::cout<<"DogFactory has been broken...."<<std::endl;
}
