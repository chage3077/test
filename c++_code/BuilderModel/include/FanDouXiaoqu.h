#ifndef FANDOUXIAOQU_H
#define FANDOUXIAOQU_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FanDouXiaoqu
{
public:
    void addHouses(string name);
    void showHouses();

private:
    vector<string> m_houses; // 用于存储好建造好的房型
};

#endif