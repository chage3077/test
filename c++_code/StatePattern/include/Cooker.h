#ifndef COOKER_H
#define COOKER_H
#include "AbstractState.h"
class Cooker
{
private:
    /* data */
    int m_clock = 0; // 当前时间点
    AbstractState *m_state = nullptr;

public:
    Cooker();
    void working();
    void setState(AbstractState *state);
    int getClock();
    void setClock(int clock);
};
#endif