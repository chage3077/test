#ifndef HOUSEBUILDER_H
#define HOUSEBUILDER_H
#include <iostream>
#include <string>
using namespace std;
class HouseBuilder
{
public:
    virtual void reset() = 0;
    virtual void makeArea() = 0;
    virtual void makeWaterRoad() = 0;
    virtual void makeElectrRoad() = 0;
    virtual void makeWall() = 0;
    virtual void makeFloor() = 0;
    virtual ~HouseBuilder() {};
};

#endif