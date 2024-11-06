#include "Australia.h"

void Australia::declare(string msg, string country)
{
    cout << "Australia is declaring...." << endl;
    // 通过中介者发布消息
    m_org->declare(msg, this, country);
}

void Australia::setMessage(string msg)
{
    cout << "Australia recv msg: " << msg << endl;
}

string Australia::getName()
{
    return "Australia";
}