#ifndef TEACHER_H
#define TEACHER_H 
#include"Identity.h"
class Teacher:public Identity
{
public:
    Teacher();
    Teacher(int id,string name,string pwd):m_Empid(id),Identity(name,pwd){}
    void setId(int id);
    int getEmpId();
    void operMenu()override;

    // 具体操作
    void showAllOrder(); // 查看所有预约
    void vaildOrder(); // 审核预约

private:
    int m_Empid;
};
#endif