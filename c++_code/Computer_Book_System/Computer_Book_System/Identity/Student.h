#ifndef STUDENT_H
#define STUDENT_H
#include"Identity.h"
#include"ComputerRoom.h"
#include"OrderInfos.h"
#include<map>
class Student:public Identity
{
private:
    int m_id; // 学生学号
    map<int,ComputerRoom> m_computers; // 机房信息
    OrderInfos* m_orderInfos; // 预约信息
public:
    Student();
    ~Student();
    Student(int id,string name,string pwd):m_id(id),Identity(name,pwd)
    {
        getComputerRoomInfo();
        m_orderInfos = new OrderInfos();
        m_orderInfos->RefreshOrderInfoMap();
    }

    int getId();
    void setId(int id);

    // 具体业务逻辑函数
    void operMenu() override; // 菜单界面
    void applyOrder(); // 申请预约
    void showMyOrder(); // 查看自己的预约
    void showAllOrder(); // 查看全部预约
    void cancelOrder(); // 取消预约

    void getComputerRoomInfo(); // 获取机房信息
};

#endif