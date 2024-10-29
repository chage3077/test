#ifndef SPEAKER_H
#define SPEAKER_H
#include "Communication.h"
// 子类——主人
class Speaker:public Communication
{
private:
    /* data */

public:
    void communicate() override;
    
};

#endif