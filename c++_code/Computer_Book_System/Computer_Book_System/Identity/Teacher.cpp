#include "Teacher.h"
Teacher::Teacher()
{
}
void Teacher::setId(int id)
{
    m_Empid = id;
}
int Teacher::getEmpId()
{
    return m_Empid;
}
void Teacher::operMenu()
{
    cout << "-----------机房管理系统-----------" << endl;
    cout << "您好，" << getName() << "老师" << endl;
    cout << "\t\t--------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  1.查看所有预约                |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  2.审核预约                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  0.注销登陆                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t--------------------------------\n";
    cout << "输入你的选择：" << endl;
}
void Teacher::vaildOrder()
{
    if (m_orderInfos == nullptr && m_orderInfos->m_orderInfos.size() == 0)
    {
        cout << "没有可处理的预约信息！" << endl;
        system("pause");
        system("cls");
        return;
    }
    vector<int> v;
    int index = 0;
    cout << "待审核的预约记录" << endl;
    for (auto it = m_orderInfos->m_orderInfos.begin(); it != m_orderInfos->m_orderInfos.end(); it++)
    {
        if (it->second["status"] == "1")
        {
            // 找到了对应的记录
            v.push_back(it->first);
            cout << ++index << "、";
            cout << "预约日期： 周" << it->second.find("data")->second << "  ";
            cout << "预约时段： " << (it->second.find("period")->second == "1" ? "上午" : "下午") << "  ";
            cout << "学号：" << it->second.find("studentId")->second << "  ";
            cout << "姓名：" << it->second.find("name")->second << "  ";
            cout << "机房编号：" << it->second.find("roomId")->second << "  ";
            string status = "状态：";
            // 1 审核中 2.已预约 -1.预约失败 0.取消预约
            if (it->second.find("status")->second == "1")
            {
                status += "审核中";
            }
            else if (it->second.find("status")->second == "2")
            {
                /* code */
                status += "预约成功";
            }
            else if (it->second.find("status")->second == "0")
            {
                status += "取消预约";
            }
            else
            {
                status += "预约失败";
            }
            cout << "审核状态：" << status << endl;
        }
    }
    if (v.size() == 0)
    {
        cout << "无需要审核的记录" << endl;
        system("pause");
        system("cls");
        return;
    }
    cout << "输入审核的预约记录，0代表返回" << endl;
    int select = 0; // 用户的选择的预约记录
    int ret = 0;    // 接收预约结果记录
    while (true)
    {
        cin >> select;
        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                /* code */
                break;
            }
            else
            {
                cout << "请输入审核结果：1代表通过，2代表未通过" << endl;
                cin >> ret;
                if (ret == 1)
                {
                    m_orderInfos->m_orderInfos.find(v[select - 1])->second["status"] = "2";
                }
                else
                {
                    m_orderInfos->m_orderInfos.find(v[select - 1])->second["status"] = "-1";
                }
                // 更新预约记录
                m_orderInfos->upDateOrderInfo();
                cout << "审核成功" << endl;
                break;
            }
        }
    }
    system("pause");
    system("cls");
}
void Teacher::showAllOrder()
{
    if (m_orderInfos == nullptr && m_orderInfos->m_orderInfos.size() == 0)
    {
        cout << "暂无预约信息" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (auto it = m_orderInfos->m_orderInfos.begin(); it != m_orderInfos->m_orderInfos.end(); it++)
    {
        cout << (it->first) + 1 << "、";
        cout << "预约日期： 周" << it->second.find("data")->second << "  ";
        cout << "预约时段： " << (it->second.find("period")->second == "1" ? "上午" : "下午") << "  ";
        cout << "学号：" << it->second.find("studentId")->second << "  ";
        cout << "姓名：" << it->second.find("name")->second << "  ";
        cout << "机房编号：" << it->second.find("roomId")->second << "  ";

        string status = "状态：";
        // 1 审核中 2.已预约 -1.预约失败 0.取消预约
        if (it->second.find("status")->second == "1")
        {
            status += "审核中";
        }
        else if (it->second.find("status")->second == "2")
        {
            /* code */
            status += "预约成功";
        }
        else if (it->second.find("status")->second == "0")
        {
            status += "取消预约";
        }
        else
        {
            status += "预约失败";
        }
        cout << "审核状态：" << status << endl;
    }
    system("pause");
    system("cls");
}