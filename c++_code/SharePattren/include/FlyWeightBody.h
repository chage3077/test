#ifndef FLYWEIGHTBODY_H
#define FLYWEIGHTBODY_H
#include <iostream>
#include <string>
using namespace std;
// 定义享元类基类
class FlyWeightBody
{
private:
    /* data */
protected:
    string m_color; // 存放颜色
    string m_spirt; // 存放精灵贴图
    string m_name;  // 享元内存的型号
public:
    FlyWeightBody(string spirt, string name) : m_spirt(spirt), m_name(name) {};
    // 纯虚函数
    virtual void move(int x, int y, int speed) = 0; // 炸弹的轨迹
    virtual void draw(int x, int y) = 0;            // 重绘炸弹的弹体
    virtual ~FlyWeightBody() {};
};
#endif