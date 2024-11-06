#include "America.h"
void America::declare(string msg, string country)
{
    cout << "America is declaring...." << endl;
    // 通过中介者发布消息
    m_org->declare(msg, this, country);
}

void America::setMessage(string msg)
{
    cout << "America recv msg: " << msg << endl;
}

string America::getName()
{
    return "America";
}