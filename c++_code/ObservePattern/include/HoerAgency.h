#ifndef HOERAGENCY_H
#define HOERAGENCY_H
#include "NewsAgency.h"
// 霍尔德报社
class HoerAgency : public NewsAgency
{
private:
    /* data */
public:
    // 发布消息
    void notify(string msg) override;
};

#endif