#ifndef TEACHER_H
#define TEACHER_H 
#include"Identity.h"
#include"OrderInfos.h"
#include<vector>
class Teacher:public Identity
{
public:
    Teacher();
    Teacher(int id,string name,string pwd):m_Empid(id),Identity(name,pwd)
    {
        m_orderInfos = new OrderInfos();
        m_orderInfos->RefreshOrderInfoMap();
    }
    void setId(int id);
    int getEmpId();
    void operMenu()override;

    // 具体操作
    void showAllOrder(); // 查看所有预约
    void vaildOrder(); // 审核预约

private:
    int m_Empid;
    OrderInfos* m_orderInfos; // 预约信息
};
#endif