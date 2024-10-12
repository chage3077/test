#include "Director.h"

void Director::setBuilder(HouseBuilder *builder)
{
    m_builder=builder;
}

void Director::buildJingjiXing()
{
    m_builder->makeArea();
    m_builder->makeWaterRoad();
}

void Director::buildBiaoZhunXing()
{
    buildJingjiXing();
    m_builder->makeElectrRoad();
    m_builder->makeFloor();
}

void Director::buildHaohuaXing()
{
    buildBiaoZhunXing();
    m_builder->makeWall();
}
