#ifndef NIANJIZHUREN_H
#define NIANJIZHUREN_H
#include "AbstructManager.h"
class Nianjizhuren : public AbstructManager
{
private:
    /* data */
public:
    void handleTask(taskType task) override;
};


#endif