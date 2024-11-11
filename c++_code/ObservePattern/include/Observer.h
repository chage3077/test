#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <string>
#include "NewsAgency.h"
using namespace std;
class Observer
{
private:
    /* data */
protected:
    NewsAgency *m_agency = nullptr;
    string m_name;

public:
    // 和报社关联
    Observer(NewsAgency *agency, string name) : m_agency(agency), m_name(name)
    {
        // 调用报社进行关联
        m_agency->attach(this);
    };
    // 和报社解除关联
    void unsubscribe();
    // 更新消息
    virtual void update(string msg) = 0;
    virtual ~Observer() {}
};

#endif