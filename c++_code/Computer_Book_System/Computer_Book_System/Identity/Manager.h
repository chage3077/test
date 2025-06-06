#ifndef MANAGER_H
#define MANAGER_H
#include <map>
#include "Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"

class Manager : public Identity
{
private:
    // 学生容器
    map<int, Student> m_Students;
    // 教师容器
    map<int, Teacher> m_Teachers;
    // 机房容器
    map<int, ComputerRoom> m_ComputerRooms;

public:
    Manager();
    Manager(string name, string pwd) : Identity(name, pwd)
    {
        InitMap();
    }

    // 具体操作
    void operMenu();
    void addPerson();    // 添加账号
    void showPerson();   // 查看账号
    void showComputer(); // 查看机房信息
    void clearFile();    // 清空预约信息

    void InitMap(); // 初始化容器
    bool checkRepeat(int id,int type); // 检测是否重复

    void printfStudents(); // 打印学生信息
    void printfTeachers(); // 打印老师信息
    void printfComputer(); // 打印机房信息
};

#endif