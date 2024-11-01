#include "SZRPcmd.h"

void SZRPcmd::execute()
{
    m_cooker->makeSZRP();
}

string SZRPcmd::name()
{
    return "shui_zhu_rou_pian";
}
