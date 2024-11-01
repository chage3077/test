#include "QJCRcmd.h"

void QJCRcmd::execute()
{
    m_cooker->makeQJCR();
}

string QJCRcmd::name()
{
    return "qing_jiao_chao_rou";
}
