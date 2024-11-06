#ifndef HISTORY_H
#define HISTORY_H
#include<iostream>
#include<string>
using namespace std;
// 历史数据类
class History
{
private:
    /* data */
    string m_msg = string();
public:
    History(string msg):m_msg(msg){}; // 封装原始数据
    string getHistory();
};
#endif