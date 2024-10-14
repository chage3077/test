#ifndef CHINESE_H
#define CHINESE_H
#include<iostream>
#include<string>
using namespace std;
class Chinese
{
private:
    /* data */
public:
    ~Chinese(){};
    void recvMessage(string text);
    string sendMessage();
};
#endif