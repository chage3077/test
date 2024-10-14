#ifndef FOREIGNER_H
#define FOREIGNER_H
#include<iostream>
#include<string>
using namespace std;
class Foreigner
{
private:
    /* data */
public:
    virtual ~Foreigner(){};
    virtual string sendMessage() = 0;
    virtual void recvMessage(string text) = 0 ;
};
#endif