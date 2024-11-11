#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H
#include<iostream>
using namespace std;
class Cooker;
class AbstractState
{
private:
    /* data */
public:
    virtual void working(Cooker* cooker) = 0;
    virtual ~AbstractState(){};
};

class MorningState:public AbstractState
{
public:
    void working(Cooker* cooker) override;
};

class NoonState:public AbstractState
{
public:
    void working(Cooker* cooker) override;
};

class AfternoonState:public AbstractState
{
public:
    void working(Cooker* cooker) override;
};
class NightState:public AbstractState
{
public:
    void working(Cooker* cooker) override;
};
#endif