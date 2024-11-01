#include "MPDFcmd.h"

void MPDFcmd::execute()
{
    // 执行命令
    m_cooker->makeMPDF();
}

string MPDFcmd::name()
{
    return "ma_po_tou_fu";
}
