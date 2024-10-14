#ifndef AMERICAN_H
#define AMERICAN_H
#include "Foreigner.h"
class American : public Foreigner
{
private:
    /* data */
public:
    ~American() {};
    void recvMessage(string text) override;
    string sendMessage() override;
};

#endif