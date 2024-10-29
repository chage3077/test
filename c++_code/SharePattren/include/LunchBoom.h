#ifndef LUNCHBOOM_H
#define LUNCHBOOM_H
#include "FlyWeightBody.h"

// 动态资源的类——发射炮弹
class LunchBoom
{
private:
    /* data */
    FlyWeightBody *m_FlyWeightBody; // 存储享元对象——静态的属性
    // 动态属性
    int m_speed = 100; // 速度
    int m_x = 0;       // 坐标轴x
    int m_y = 0;       // 坐标轴y
public:
    LunchBoom(FlyWeightBody *flyWeightBody) : m_FlyWeightBody(flyWeightBody) {}; // 制造弹体（享元）
    void setSeep(int speed);
    // 移动
    void move(int x, int y);
    // 重绘
    void draw();
    
};
#endif