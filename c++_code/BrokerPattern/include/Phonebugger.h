#ifndef PHONEBUGGER_H
#define PHONEBUGGER_H
#include "Speaker.h"
class Phonebugger : public Communication
{
private:
    /* data */
    bool m_IsStart = false; // 用于记录是否打开代理
    Speaker* m_speaker = nullptr; // 用于记录自己的主人
public:
    bool isStart();
    void setStart(bool flag);
    void communicate() override;
    Phonebugger();
    ~Phonebugger(/* args */);
    
};
#endif