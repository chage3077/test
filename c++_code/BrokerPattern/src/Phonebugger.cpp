#include "Phonebugger.h"

bool Phonebugger::isStart()
{
    return m_IsStart;
}

void Phonebugger::setStart(bool flag)
{
    m_IsStart = flag;
}

void Phonebugger::communicate()
{
    // 判断是否打开代理模式
    if (m_IsStart)
    {
        cout << "The Phonebugger is connecting with speaker....." << endl;
        m_speaker->communicate();
    }
}

Phonebugger::~Phonebugger()
{
    // 释放资源
    if (m_speaker != nullptr)
    {
        delete m_speaker;
    }
}

Phonebugger::Phonebugger()
{
    m_IsStart = true;        // 开启代理
    m_speaker = new Speaker; // 新开辟主人空间
}
