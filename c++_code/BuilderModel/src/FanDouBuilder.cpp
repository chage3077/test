#include "FanDouBuilder.h"

// 可以创造不同的小区，每次创建新的对象即可
// new出新的地址
void FanDouBuilder::reset()
{
    m_xiaoqu = new FanDouXiaoqu;
}

void FanDouBuilder::makeArea()
{
    m_xiaoqu->addHouses("The area is 80.");
}

void FanDouBuilder::makeWaterRoad()
{
    m_xiaoqu->addHouses("Finish water.");
}

void FanDouBuilder::makeElectrRoad()
{
    m_xiaoqu->addHouses("Finish electry");
}

void FanDouBuilder::makeWall()
{
    m_xiaoqu->addHouses("Finish wall");
}

void FanDouBuilder::makeFloor()
{
    m_xiaoqu->addHouses("Finish floor");
}

FanDouBuilder::FanDouBuilder()
{
    reset();
}

FanDouBuilder::~FanDouBuilder()
{
    if (m_xiaoqu)
        delete m_xiaoqu;
}

FanDouXiaoqu *FanDouBuilder::getXiaoqu()
{
    // 创建新的小区之前可以获取旧小区的地址
    FanDouXiaoqu *t_xiaoqu = m_xiaoqu;
    // 清空旧小区的地址
    m_xiaoqu = nullptr;
    return t_xiaoqu;
}
