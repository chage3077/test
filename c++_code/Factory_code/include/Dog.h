#ifndef DOG_H
#define DOG_H
#include "Animal.h"
class Dog : public Animal
{
private:
    /* data */
public:
    Dog();
    virtual ~Dog();
    void Sound() override; //override的作用是检查函数名是否对应父类
    void Behavior() override;
};

#endif