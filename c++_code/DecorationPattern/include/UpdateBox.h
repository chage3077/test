#ifndef UPDATEBOX_H
#define UPDATEBOX_H
#include "Car.h"
class UpdateBox : public Car
{
private:
    /* data */
protected:
    Car *m_car = nullptr;
public:
    
    void updateToCar(Car *car); // 为升级盒子指定载体
};
#endif