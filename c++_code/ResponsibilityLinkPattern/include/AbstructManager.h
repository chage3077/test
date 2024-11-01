#ifndef ABSTRUCTMANAGER_H
#define ABSTRUCTMANAGER_H
#include <iostream>
using namespace std;
enum struct taskType : char
{
    qiangjia,
    chaxuefen,
    zhuanzhuanye,
    tuixue,
    xiuxue
};

class AbstructManager
{
private:
    /* data */
protected:
    AbstructManager *m_next = nullptr;

public:
    virtual void handleTask(taskType task) = 0;
    void setNextManager(AbstructManager *manager);
    virtual ~AbstructManager(){};
};
#endif