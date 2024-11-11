#ifndef MAIERAGENCY_H
#define MAIERAGENCY_H
#include "NewsAgency.h"
class MaierAgency : public NewsAgency
{
private:
    /* data */
public:
    // 发布消息
    void notify(string msg) override;
};
#endif