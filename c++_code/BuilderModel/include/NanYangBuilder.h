#ifndef NANYANGBUILDER_H
#define NANYANGBUILDER_H
#include "HouseBuilder.h"
#include "NanYangXiaoqu.h"
#include <iostream>
#include <string>
class NanYangBuilder : public HouseBuilder
{
private:
    /* data */
    NanYangXiaoqu* m_xiaoqu;
public:
    void reset();
    void makeArea();
    void makeWaterRoad();
    void makeElectrRoad();
    void makeWall();
    void makeFloor();
    NanYangXiaoqu* getXiaoqu();
    NanYangBuilder(/* args */);
    ~NanYangBuilder();

};
#endif