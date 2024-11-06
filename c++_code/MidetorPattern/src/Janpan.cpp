#include "Janpan.h"

void Janpan::declare(string msg, string country)
{
    cout << "Janpan is declaring...." << endl;
    // 通过中介者发布消息
    m_org->declare(msg, this, country);
}

void Janpan::setMessage(string msg)
{
    cout << "Janpan recv msg: " << msg << endl;
}

string Janpan::getName()
{
    return "Janpan";
}