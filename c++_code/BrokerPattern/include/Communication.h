#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <iostream>
#include <string>
using namespace std;
// 通信基类
class Communication
{
private:
    virtual void communicate() = 0; // 用于通信的方法
public:
    virtual ~Communication() {};
};

#endif