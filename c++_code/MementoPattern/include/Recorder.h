#ifndef RECORDER_H
#define RECORDER_H
#include<iostream>
#include<string>
#include<map>
#include"History.h"
using namespace std;
class Recorder
{
private:
    /* data */
    map<int,History*>m_historyMap;
public:
    void addHistory(int index,History* history);
    History* getHistory(int index);
};

#endif