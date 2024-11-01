#include "SJcmd.h"

void SJcmd::execute()
{
    m_cooker->makeSJ();
}

string SJcmd::name()
{
    return "shao_ji";
}
