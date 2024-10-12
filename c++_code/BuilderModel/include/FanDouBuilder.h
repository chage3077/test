#ifndef FANDOUBUILDER_H
#define FANDOUBUILDER_H
#include "HouseBuilder.h"
#include "FanDouXiaoqu.h"
#include <iostream>
#include <string>
using namespace std;
class FanDouBuilder : public HouseBuilder
{
public:
    void reset() override;
    void makeArea ()override;
    void makeWaterRoad()override;
    void makeElectrRoad()override;
    void makeWall()override;
    void makeFloor()override;
    FanDouBuilder();
    ~FanDouBuilder();
    FanDouXiaoqu* getXiaoqu();
private:
    // 存储房子
    FanDouXiaoqu* m_xiaoqu;
};

#endif