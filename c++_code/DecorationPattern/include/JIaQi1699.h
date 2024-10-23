#ifndef JiaQi1699_H
#define JiaQi1699_H
#include "Car.h"
// 定义汽车某款车型
class JIaQi1699 : public Car
{
private:
    /* data */
public:
    using Car::Car;
    void function() override;
};
#endif