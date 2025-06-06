#include "Student.h"
#include "globalFile.h"
#include <fstream>
Student::Student()
{
}

Student::~Student()
{
    if(m_orderInfos!=nullptr)
        delete m_orderInfos;
}

int Student::getId()
{
    return m_id;
}

void Student::setId(int id)
{
    m_id = id;
}

void Student::operMenu()
{
    cout << "-----------机房管理系统-----------" << endl;
    cout << "你好，" << getName() << endl;
    cout << "\t\t--------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  1.申请预约                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  2.查看自身预约                |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  3.查看所有预约                |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  4.取消预约                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  0.注销登陆                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t--------------------------------\n";
    cout << "输入你的选择：" << endl;
}

void Student::applyOrder()
{
    // 申请一条预约
    // 包括机房号，日期，时段
    cout << "机房开放时间为周一到周五" << endl;
    cout << "请输入申请预约的时间：" << endl;
    cout << "1.周一" << endl;
    cout << "2.周二" << endl;
    cout << "3.周三" << endl;
    cout << "4.周四" << endl;
    cout << "5.周五" << endl;

    int data;
    int period; // 时间段
    int roomId; // 机房编号

    while (true)
    {
        cin >> data;
        if (data >= 1 && data <= 5)
        {
            break;
        }
        cout << "请在预约的时间内进行预约，请重新输入：" << endl;
    }

    cout << "预约为上午或下午" << endl;
    cout << "请输入申请预约的时间段：" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;
    while (true)
    {
        cin >> period;
        if (data >= 1 && data <= 2)
        {
            break;
        }
        cout << "请在合适的时间段预约，请重新输入：" << endl;
    }

    cout << "选择预约的机房" << endl;
    for (auto it = m_computers.begin(); it != m_computers.end(); it++)
    {
        cout << it->second.getRoomId() << "号机房的容量：" << it->second.getMaxNum() << endl;
    }
    while (true)
    {
        cin >> roomId;
        if (data >= 1 && data <= 3)
        {
            break;
        }
        cout << "请预约正确的机房，请重新输入：" << endl;
    }

    cout << "预约成功" << endl;

    // 写入文件中
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);
    if(!ofs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    ofs << "data:" << data << " ";
    ofs << "period:" << period << " ";
    ofs << "studentId:" << m_id << " ";
    ofs << "name:" << getName() << " ";
    ofs << "roomId:" << roomId << " ";
    ofs << "status:" << "审核中" << endl;

    ofs.close();

    system("pause");
    system("cls");
}

void Student::showMyOrder()
{
}

void Student::showAllOrder()
{
    m_orderInfos->printOrderInfo();
}

void Student::cancelOrder()
{
}

void Student::getComputerRoomInfo()
{
    ifstream in;
    in.open(COMPUTER_FILE, ios::in);
    ComputerRoom room;
    int rId;
    int rMaxNum;
    while (in >> rId && in >> rMaxNum)
    {
        /* code */
        room.setRoomId(rId);
        room.setMaxNum(rMaxNum);
        m_computers.insert(make_pair(rId, room));
    }
    cout << "机房信息读取完毕" << endl;
    cout << "目前录入机房信息：" << endl;
    in.close();
    // for(auto it = m_computers.begin(); it != m_computers.end(); it++)
    // {
    //     cout << "机房号：" << it->second.getRoomId() << " 机房最大容量：" << it->second.getMaxNum() << endl;
    // }
}
