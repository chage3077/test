#include "NanYangBuilder.h"

// 可以创造不同的小区，每次创建新的对象即可
// new出新的地址
void NanYangBuilder::reset()
{
    m_xiaoqu = new NanYangXiaoqu;
}

void NanYangBuilder::makeArea()
{
    m_xiaoqu->assemble("The area is 490","Area");
}

void NanYangBuilder::makeWaterRoad()
{
    m_xiaoqu->assemble("Finish surper water","water_sys");
}

void NanYangBuilder::makeElectrRoad()
{
    m_xiaoqu->assemble("Finish surper electry","electry_sys");
}

void NanYangBuilder::makeWall()
{
    m_xiaoqu->assemble("Finish surper wall","wall");
}

void NanYangBuilder::makeFloor()
{
    m_xiaoqu->assemble("Finish super floor","floor");
}

NanYangBuilder::NanYangBuilder()
{
    reset();
}

NanYangBuilder::~NanYangBuilder()
{
    if (m_xiaoqu)
        delete m_xiaoqu;
}

NanYangXiaoqu* NanYangBuilder::getXiaoqu()
{
    // 创建新的小区之前可以获取旧小区的地址
    NanYangXiaoqu *t_xiaoqu = m_xiaoqu;
    // 清空旧小区的地址
    m_xiaoqu = nullptr;
    return t_xiaoqu;
}
