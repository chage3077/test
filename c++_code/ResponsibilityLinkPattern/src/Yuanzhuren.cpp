#include "Yuanzhuren.h"

void Yuanzhuren::handleTask(taskType task)
{
    switch (task)
    {
    case taskType::chaxuefen:
        cout << "You should find your Fudaoyuan................" << endl;
        cout << "Your goal is 55." << endl;
        break;
    case taskType::qiangjia:
        cout << "The next time You should find your Fudaoyuan.Agree your qingjia request................" << endl;
        break;
    case taskType::zhuanzhuanye:
        cout << "You should find your Nianjizhuren................" << endl;
        cout << "you can submit your zhuanzhuanye request.........." << endl;
        break;
    case taskType::xiuxue:
        cout << "Agree your xiuxue request..........I call your parents." << endl;
    case taskType::tuixue:
        cout << "Don't agree your tuixue request..........I call your parents." << endl;
    default:
        break;
    }
}