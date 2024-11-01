#ifndef FUDAOYUAN_H
#define FUDAOYUAN_H
#include"AbstructManager.h"
class Fudaoyuan:public AbstructManager
{
private:
    /* data */
public:
    void handleTask(taskType task) override;
    
};
#endif