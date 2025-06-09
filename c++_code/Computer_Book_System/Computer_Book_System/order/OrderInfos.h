#ifndef ORDERINFO_H
#define ORDERINFO_H
#include <iostream>
#include <string>
#include <map>
using namespace std;
struct OrderInfo
{
    string m_data;    // 预约的日期
    string m_period;  // 预约的时间段
    string m_stuId;   // 学生预约的id
    string m_stuName; // 学生的姓名
    string m_roomId;  // 预约的机房编号
    string m_status;  // 审核状态

    OrderInfo()
    {
        m_data = "";
        m_period = "";
        m_stuId = "";
        m_stuName = "";
        m_roomId = "";
        m_status = "";
    }
    OrderInfo(int data, int period, int stuId, string stuName, int roomId, int status)
    {
        m_data = data;
        m_period = period;
        m_stuId = stuId;
        m_stuName = stuName;
        m_roomId = roomId;
        m_status = status;
    }
};
class OrderInfos
{
private:
    int m_size;                                 // 预约记录条数
public:
    map<int, map<string, string>> m_orderInfos; // 预约信息，首先大map记录所有的预约信息，小map保存预约每一条信息，记录字段属性和信息
    OrderInfos();
    void upDateOrderInfo();
    void RefreshOrderInfoMap();
    void printOrderInfo();

    int getSize();
};
#endif