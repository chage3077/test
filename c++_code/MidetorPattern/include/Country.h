#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
#include <string>
#include "Mediator.h"
using namespace std;
// 定义国家的基类
class Country
{
private:
    /* data */
protected:
    Mediator *m_org = nullptr;

public:
    Country(Mediator *org) : m_org(org) {};
    virtual void declare(string msg, string country) = 0; // 对其他国家进行宣言
    virtual void setMessage(string msg) = 0;              // 接收其他国家的消息
    virtual string getName() = 0;                         // 获取该国家的名字
    virtual ~Country() {};
};
#endif