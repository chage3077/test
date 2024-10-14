#include "English.h"

void English::recvMessage(string text)
{
    cout << text << endl;
}

string English::sendMessage()
{
    string msg = "Hello,I am English.";
    return msg;
}
