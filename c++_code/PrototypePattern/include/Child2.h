#ifndef CHILD2_H
#define CHILD2_H
#include<iostream>
#include <string>
#include "Father.h"
using namespace std;
class Child2:public Father
{
private:
    string name;
public:
    Child2():name("Child2"){};
    Father* getClone() override;//调用Child1的拷贝构造函数
    string getIndentity() override; // 测试函数，获取身份
}; 
#endif