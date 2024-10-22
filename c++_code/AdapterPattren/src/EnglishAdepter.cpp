#include "EnglishAdepter.h"

void EnglishAdepter::translateToChinese()
{
    // 将语言翻译成中文
    // 1.先获取外国人的信息
    string msg = m_foreigner->sendMessage();
    // 2.经过一系列处理，发送给中国
    m_Chinese->recvMessage("English says:"+msg);
}

void EnglishAdepter::transloateToForeign()
{
    // 将语言转换成英文
    // 1.获取中国人发送的信息
    string msg = m_Chinese->sendMessage();
    // 经过一些列处理发送给英国
    m_foreigner->recvMessage("Chinese says:"+msg);
}