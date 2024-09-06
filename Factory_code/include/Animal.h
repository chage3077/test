#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
class Animal
{
private:
    /* data */
public:
    std::string name;
    Animal(/* args */) {}
    virtual ~Animal() {}
    virtual void Sound() = 0;
    virtual void Behavior() = 0;
};
#endif