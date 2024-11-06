#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <string>
#include <map>
using namespace std;
class Country;
// 定义中介者基类
class Mediator
{
private:
    /* data */
public:
    void addCountry(Country *country);                                   // 添加国家到中介者类中
    virtual void declare(string msg, Country *country, string name) = 0; // 为国家宣言
    virtual ~Mediator() {};

protected:
    map<string, Country *> m_countryMap; // 存储国家信息
};
#endif