#ifndef AUSTRALIA_H
#define AUSTRALIA_H
#include"Country.h"
class Australia:public Country
{
private:
    /* data */
public:
    using Country::Country;
    void declare(string msg, string country)override; // 对其他国家进行宣言
    void setMessage(string msg)override;              // 接收其他国家的消息
    string getName()override;
};
#endif