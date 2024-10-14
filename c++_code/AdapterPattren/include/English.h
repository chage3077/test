#ifndef ENGLISH_H
#define ENGLISH_H
#include"Foreigner.h"
class English:public Foreigner
{
private:
    /* data */
public:
    void recvMessage(string text) override;
    string sendMessage() override;
    ~English(){};
};
#endif