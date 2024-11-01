#ifndef YUANZHUREN_H
#define YUANZHUREN_H
#include "AbstructManager.h"
class Yuanzhuren:public AbstructManager
{
private:
    /* data */
public:
    void handleTask(taskType task) override;
};
#endif