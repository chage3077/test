#ifndef NANYANGXIAOQU_H
#define NANYANGXIAOQU_H
#include <iostream>
#include <string>
#include <map>
using namespace std;

class NanYangXiaoqu
{
public:
    void assemble(string type_name,string house_name);
    void showHouses();

private:
    map<string,string> m_houses; // 用于存储好建造好的房型
};

#endif