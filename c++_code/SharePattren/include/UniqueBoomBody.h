#ifndef UNIQUEBOOMBODY_H
#define UNIQUEBOOMBODY_H
#include "FlyWeightBody.h"

// 享元类的子类——独享内存的彩蛋
class UniqueBoomBody : public FlyWeightBody
{
private:
    /* data */
public:
    using FlyWeightBody::FlyWeightBody;
    // 重写
    void move(int x, int y, int speed) override; // 炸弹的轨迹
    void draw(int x, int y) override;            // 重绘炸弹的弹体
};
#endif