#ifndef CAT_H
#define CAT_H
#include "Animal.h"
class Cat : public Animal
{
private:
    /* data */
public:
    Cat();
    virtual ~Cat();
    void Sound() override;
    void Behavior() override;
};

#endif