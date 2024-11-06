#include "Chinese.h"

void Chinese::declare(string msg, string country)
{
    cout << "Chinese is declaring...." << endl;
    // 通过中介者发布消息
    m_org->declare(msg, this, country);
}

void Chinese::setMessage(string msg)
{
    cout << "Chinese recv msg: " << msg << endl;
}

string Chinese::getName()
{
    return "Chinese";
}
