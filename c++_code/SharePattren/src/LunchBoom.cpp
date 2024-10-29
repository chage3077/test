#include "LunchBoom.h"

void LunchBoom::setSeep(int speed)
{
    m_speed = speed;
}

void LunchBoom::move(int x, int y)
{
    m_x = x;
    m_y = y;
    // 弹体移动
    m_FlyWeightBody->move(m_x, m_y, m_speed);
    // 每次移动后就重绘
    draw();
}

void LunchBoom::draw()
{
    // 重绘炮弹
    m_FlyWeightBody->draw(m_x, m_y);
}
