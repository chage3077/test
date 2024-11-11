#ifndef FAN_H
#define FAN_H
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
enum class Weather:char{cool,normal,hot};
class Fan
{
private:
    AbstractStrategy* m_stratehy = nullptr;
public:
    void start(Weather weather);
    ~Fan();
};
#endif