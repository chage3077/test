#ifndef ABSTRACTSTRATEGY_H
#define ABSTRACTSTRATEGY_H
#include <iostream>
#include <string>
using namespace std;
class AbstractStrategy
{
private:
    /* data */
public:
    virtual void function() = 0;
    virtual ~AbstractStrategy() {}
};
#endif