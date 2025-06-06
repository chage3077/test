#include "OrderInfos.h"
#include "globalFile.h"
#include <fstream>
OrderInfos::OrderInfos()
{
    m_size = 0;
}

void OrderInfos::upDateOrderInfo()
{
    if (m_size == 0)
    {
        return;
    }
    // 重新写
    ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
    if (!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    for (int i = 0; i < m_size; i++)
    {
        ofs << "data:" << m_orderInfos[i]["data"] << " ";
        ofs << "period:" << m_orderInfos[i]["period"] << " ";
        ofs << "studentId:" << m_orderInfos[i]["studentId"] << " ";
        ofs << "name:" << m_orderInfos[i]["name"] << " ";
        ofs << "roomId:" << m_orderInfos[i]["roomId"] << " ";
        ofs << "status:" << m_orderInfos[i]["status"] << endl;
    }
    ofs.close();
}

void OrderInfos::RefreshOrderInfoMap()
{
    // 读取文件
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);

    // 准备解析数据
    string key;
    string value;
    map<string, string> m;
    int pos; // 截取的位置
    OrderInfo *orderInfo = new OrderInfo();
    while (orderInfo != nullptr && ifs >> orderInfo->m_data && ifs >> orderInfo->m_period && ifs >> orderInfo->m_stuId && ifs >> orderInfo->m_stuName && ifs >> orderInfo->m_roomId && ifs >> orderInfo->m_status)
    {
        // 1.解析data，由:分割，可以截子串分别得到key和value
        pos = orderInfo->m_data.find(":");
        if (pos != -1)
        {
            key = orderInfo->m_data.substr(0, pos); // 截取位置，截取字符的数量
            value = orderInfo->m_data.substr(pos + 1, orderInfo->m_data.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        // 2.解析period
        pos = orderInfo->m_period.find(":");
        if (pos != -1)
        {
            key = orderInfo->m_period.substr(0, pos); // 截取位置，截取字符的数量
            value = orderInfo->m_period.substr(pos + 1, orderInfo->m_period.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        // 3.解析stuId
        pos = orderInfo->m_stuId.find(":");
        if (pos != -1)
        {
            key = orderInfo->m_stuId.substr(0, pos); // 截取位置，截取字符的数量
            value = orderInfo->m_stuId.substr(pos + 1, orderInfo->m_stuId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        // 4.解析名字
        pos = orderInfo->m_stuName.find(":");
        if (pos != -1)
        {
            key = orderInfo->m_stuName.substr(0, pos); // 截取位置，截取字符的数量
            value = orderInfo->m_stuName.substr(pos + 1, orderInfo->m_stuName.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        // 5.解析机房编号
        pos = orderInfo->m_roomId.find(":");
        if (pos != -1)
        {
            key = orderInfo->m_roomId.substr(0, pos); // 截取位置，截取字符的数量
            value = orderInfo->m_roomId.substr(pos + 1, orderInfo->m_roomId.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        // 6.解析预约状态
        pos = orderInfo->m_status.find(":");
        if (pos != -1)
        {
            key = orderInfo->m_status.substr(0, pos); // 截取位置，截取字符的数量
            value = orderInfo->m_status.substr(pos + 1, orderInfo->m_status.size() - pos - 1);
            m.insert(make_pair(key, value));
        }
        // 将小map放到大map中
        m_size++;
        m_orderInfos.insert(make_pair(m_size, m));
        m.clear(); // 清空小map继续更新
    }
    ifs.close();
    delete orderInfo; // 释放内存
}

void OrderInfos::printOrderInfo()
{
    for (auto it = m_orderInfos.begin(); it != m_orderInfos.end(); it++)
    {
        cout << "预约key:" << it->first << endl;
        for (auto iit = it->second.begin(); iit != it->second.end(); iit++)
        {
            cout << iit->first << ":" << iit->second << endl;
        }
        cout << endl;
    }
}

int OrderInfos::getSize()
{
    return m_size;
}
