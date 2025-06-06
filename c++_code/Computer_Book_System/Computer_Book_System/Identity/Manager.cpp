#include "Manager.h"
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include <fstream>
using namespace std;
Manager::Manager()
{
}
void Manager::operMenu()
{
    cout << "-----------机房管理系统-----------" << endl;
    cout << "欢迎您管理员:" << getName() << endl;
    cout << "\t\t--------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  1.添加账号                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  2.查看账号                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  3.查看机房                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  4.清空预约                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  0.注销登陆                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t--------------------------------\n";
    cout << "输入你的选择：" << endl;
}
void Manager::addPerson() // 添加账号
{
    cout << "输入添加的账号类型：" << endl;
    cout << "1.添加学生" << endl;
    cout << "2.添加教师" << endl;

    string filename;
    string tip; // 提示的id号
    string errorTip;
    ofstream out;

    int select;
    cin >> select;

    switch (select)
    {
    case 1:
        /* code */
        // 添加学生
        filename = STUDENT_FILE;
        tip = "请输入学号";
        errorTip = "学号重复，请重新输入";
        break;
    case 2:
        // 添加教师
        filename = TEACHER_FILE;
        tip = "请输入职工号";
        errorTip = "职工号重复，请重新输入";
        break;
    default:
        break;
    }

    // 追加写文件
    out.open(filename, ios::out | ios::app);
    int id;
    string name;
    string pwd;
    while (true)
    {
        /* code */
        cout << tip << endl;
        cin >> id;
        bool ret = checkRepeat(id, select);
        if (ret)
        {
            cout << errorTip << endl;
        }
        else
            break;
    }
    cout << "姓名：" << endl;
    cin >> name;
    cout << "密码：" << endl;
    cin >> pwd;
    // 向文件中添加
    out << id << " " << name << " " << pwd << endl;
    cout << "添加成功" << endl;

    // 添加结束后再跟新容器
    InitMap(); // 再次文件中更新容器
    system("pause");
    system("cls");

    out.close();
}
void Manager::showPerson() // 查看账号
{
    cout << "显示账号类型：" << endl;
    cout << "1.显示学生账号" << endl;
    cout << "2.显示老师账号" << endl;

    int select;
    cin >> select;
    // 接收结果
    switch (select)
    {
    case 1:
        // 显示学生账号
        printfStudents();
        break;
    case 2:
        // 显示老师账号
        printfTeachers();
        break;
    }
    system("pause");
    system("cls");
}
void Manager::showComputer() // 查看机房信息
{
    printfComputer();
    system("pause");
    system("cls");
}
void Manager::clearFile() // 清空预约信息
{
    ofstream out(ORDER_FILE, ios::trunc); // ios::trunc表示清空文件
    out.close();

    cout << "清空成功！" << endl;
    system("pause");
    system("cls");
}

void Manager::InitMap()
{
    // 读取学生文件
    ifstream in;
    in.open(STUDENT_FILE, ios::in);
    if (!in.is_open())
    {
        cout << "文件不存在" << endl;
        return;
    }

    // 清空
    m_Students.clear();
    m_Teachers.clear();

    // 添加学生容器
    Student stu;
    int id;
    string pwd;
    string name;
    while (in >> id && in >> name && in >> pwd)
    {
        stu.setId(id);
        stu.setName(name);
        stu.setPwd(pwd);
        m_Students.insert(make_pair(id, stu));
    }
    cout << "学生信息读取完毕" << endl;
    cout << "目前录入学生人数：" << m_Students.size() << endl;
    in.close();

    in.open(TEACHER_FILE, ios::in);
    // 添加老师容器
    Teacher tea;
    while (in >> id && in >> name && in >> pwd)
    {
        tea.setId(id);
        tea.setName(name);
        tea.setPwd(pwd);
        m_Teachers.insert(make_pair(id, tea));
    }
    cout << "老师信息读取完毕" << endl;
    cout << "目前录入老师人数：" << m_Teachers.size() << endl;
    in.close();

    // 初始机房信息
    in.open(COMPUTER_FILE, ios::in);
    if (!in.is_open())
    {
        /* code */
        cout << "文件打开失败" << endl;
        return;
    }
    ComputerRoom room;
    int rId;
    int rMaxNum;
    while (in >> rId && in >> rMaxNum)
    {
        /* code */
        room.setRoomId(rId);
        room.setMaxNum(rMaxNum);
        m_ComputerRooms.insert(make_pair(rId, room));
    }
    cout << "机房信息读取完毕" << endl;
    cout << "目前录入机房数量：" << m_ComputerRooms.size() << endl;
    in.close();
}

bool Manager::checkRepeat(int id, int type)
{
    if (type == 1) // 检测学生
    {
        if (m_Students.find(id) != m_Students.end())
        {
            cout << "该学号已存在账号，请重新输入" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
    else // 检测老师
    {
        if (m_Teachers.find(id) != m_Teachers.end())
        {
            cout << "该工号已存在账号，请重新输入" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Manager::printfStudents()
{
    for (auto it = m_Students.begin(); it != m_Students.end(); it++)
    {
        cout << "学号：" << it->second.getId() << " 姓名：" << it->second.getName() << " 密码：" << it->second.getPwd() << endl;
    }
}

void Manager::printfTeachers()
{
    for (auto it = m_Teachers.begin(); it != m_Teachers.end(); it++)
    {
        cout << "工号：" << it->second.getEmpId() << " 姓名：" << it->second.getName() << " 密码：" << it->second.getPwd() << endl;
    }
}

void Manager::printfComputer()
{
    for (auto it = m_ComputerRooms.begin(); it != m_ComputerRooms.end(); it++)
    {
        cout << "机房编号：" << it->second.getRoomId() << " 最大预约数：" << it->second.getMaxNum() << endl;
    }
}
