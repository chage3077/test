#ifndef CHILD1_H
#define CHILD1_H
#include<iostream>
#include <string>
#include "Father.h"
using namespace std;
class Child1:public Father
{
private:
    string name;
public:
    Child1():name("Child1"){};
    Father* getClone() override;//调用Child1的拷贝构造函数
    string getIndentity() override; // 测试函数，获取身份
}; 
#endif