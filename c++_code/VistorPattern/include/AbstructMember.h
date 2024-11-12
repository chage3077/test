#ifndef ABSTRUCTMEMBER_H
#define ABSTRUCTMEMBER_H
// 成员类基类
#include <iostream>
#include <string>
#include "AbstructAction.h"
using namespace std;
class AbstructMember
{
private:
    /* data */
protected:
    string m_name;

public:
    AbstructMember(string name) : m_name(name) {}
    string getName();
    virtual ~AbstructMember() {}
    virtual void accept(AbstructAction *action) = 0; // 访问行为的接口
};
#endif