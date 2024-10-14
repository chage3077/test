#include "Chinese.h"

void Chinese::recvMessage(string text)
{
    cout<<text<<endl;
}

string Chinese::sendMessage()
{
    string msg = "Hello,I am Chinese.";
    return msg;
}
