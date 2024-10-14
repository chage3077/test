#include "American.h"

void American::recvMessage(string text)
{
    cout << text << endl;
}

string American::sendMessage()
{
    string msg = "Hello,I am American.";
    return msg;
}
