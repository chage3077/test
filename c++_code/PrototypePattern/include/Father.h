#ifndef FATHER_H
#define FATHER_H
#include<iostream>
#include <string>
using namespace std;
class Father
{
public:
    virtual Father* getClone() = 0;
    virtual string getIndentity() = 0;
    virtual ~Father(){};
};
#endif