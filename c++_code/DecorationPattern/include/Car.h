#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
using namespace std;
// 汽车基类
class Car
{
public:
    Car(){}
    Car(string name) : m_name(name) {}
    string getName();
    virtual void function() = 0; // 区分不同的发展方向
    virtual ~Car() {}

protected:
    string m_name = string();

private:
};
#endif