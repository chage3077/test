#include "Cook.h"
#include "Stuff.h"
#include "MPDFcmd.h"
#include "SJcmd.h"
#include "SZRPcmd.h"
#include "QJCRcmd.h"
int main()
{
    // 厨师
    Cook *cooker = new Cook;
    // 服务员
    Stuff *stuff = new Stuff;
    // 命令
    AbstructCommand *mpdf = new MPDFcmd(cooker);
    AbstructCommand *sj = new SJcmd(cooker);
    AbstructCommand *szrp = new SZRPcmd(cooker);
    AbstructCommand *qjcr = new QJCRcmd(cooker);

    // 开始点菜
    cout << "---------Start Ordering------------" << endl;
    cout << "Table:451" << endl;
    stuff->setOrder(451, mpdf);
    stuff->setOrder(451, sj);
    stuff->setOrder(451, szrp);
    stuff->setOrder(451, qjcr);

    cout << "Table:897" << endl;
    stuff->setOrder(897, mpdf);
    stuff->setOrder(897, qjcr);
    stuff->setOrder(897, sj);

    // 顾客需要取消某些菜品
    cout << "---------Removing---------------" << endl;
    stuff->deleteOrder(897, sj);

    // 服务员正式下单
    cout << "--------Starting cooking----------" << endl;
    stuff->notify(451);
    stuff->notify(897);

    // 结账
    cout << "--------Starting checking----------" << endl;
    stuff->checkOut(451);
    stuff->checkOut(897);

    // 释放内存
    delete cooker;
    delete stuff;
    delete mpdf;
    delete sj;
    delete szrp;
    delete qjcr;

    return 0;
}