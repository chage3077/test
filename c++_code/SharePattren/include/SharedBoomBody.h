#ifndef SHAREBOOMBODY_H
#define SHAREBOOMBODY_H
#include "FlyWeightBody.h"

// 享元类的子类——炮弹
class SharedBoomBody : public FlyWeightBody
{
private:
    /* data */
public:
    using FlyWeightBody::FlyWeightBody; // 继承父类的构造函数
    // 重写
    void move(int x, int y, int speed) override; // 炸弹的轨迹
    void draw(int x, int y) override;            // 重绘炸弹的弹体
};
#endif