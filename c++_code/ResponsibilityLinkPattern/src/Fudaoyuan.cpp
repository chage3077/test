#include "Fudaoyuan.h"

void Fudaoyuan::handleTask(taskType task)
{
    // 处理事物
    switch (task)
    {
    case taskType::chaxuefen:
        cout << "Agree your chaxuefen request................" << endl;
        cout << "Your goal is 55." << endl;
        break;
    case taskType::qiangjia:
        cout << "Agree your qingjia request................" << endl;
        break;
    case taskType::zhuanzhuanye:
        cout << "I can't agree your request, I submit your request to nianjizhuren.........." << endl;
        m_next->handleTask(task);
        break;
    case taskType::xiuxue:
        cout << "I can't agree your request, I submit your request to nianjizhuren.........." << endl;
        m_next->handleTask(task);
    case taskType::tuixue:
        cout << "I can't agree your request, I submit your request to nianjizhuren.........." << endl;
        m_next->handleTask(task);
    default:
        break;
    }
}