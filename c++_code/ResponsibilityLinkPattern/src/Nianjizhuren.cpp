#include "Nianjizhuren.h"

void Nianjizhuren::handleTask(taskType task)
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
        cout << "OK,you can submit your zhuanzhuanye request.........." << endl;
        break;
    case taskType::xiuxue:
        cout << "I can't agree your request, I submit your request to Yuanzhuren.........." << endl;
        m_next->handleTask(task);
    case taskType::tuixue:
        cout << "I can't agree your request, I submit your request to Yuanzhuren.........." << endl;
        m_next->handleTask(task);
    default:
        break;
    }
}