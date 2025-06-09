#include "MenuMgr.h"
#include"Manager.h"
using namespace std;
MenuMgr::MenuMgr()
{
}

void MenuMgr::showMainMenu()
{
    cout << "-----------机房管理系统-----------" << endl;
    cout << endl
         << "输入你的身份"
         << endl;
    cout << "\t\t--------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  1.学生代表                   |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  2.老师                       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  3.管理员                     |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  4.退出                       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t--------------------------------\n";
    cout << "输入你的选择：" << endl;
}

void MenuMgr::showManagerMenu(Identity *person)
{
    while (true)
    {
        // 调用子类的管理员的菜单
        person->operMenu();

        // 将父类指针转换成子类的指针
        Manager *mgr = dynamic_cast<Manager *>(person);

        int select = 0;
        // 接收用户的选择
        cin >> select;
        switch (select)
        {
        case 1:
            /* code */
            // 添加账号
            cout << "添加账号" << endl;
            mgr->addPerson();
            break;
        case 2:
            // 查看账号
            cout << "查看账号" << endl;
            mgr->showPerson();
            break;
        case 3:
            // 查看机房
            cout << "查看机房" << endl;
            mgr->showComputer();
            break;
        case 4:
            // 清空预约
            cout << "清空预约" << endl;
            mgr->clearFile();
            break;
        default:
            // 默认其他操作值为退出登陆
            delete mgr; // 销毁堆区对象
            cout << "退出成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void MenuMgr::showStudentMenu(Identity *person)
{
    while (true)
    {
        // 调用子类的管理员的菜单
        person->operMenu();

        // 将父类指针转换成子类的指针
        Student *stu = dynamic_cast<Student *>(person);

        int select = 0;
        // 接收用户的选择
        cin >> select;
        switch (select)
        {
        case 1:
            /* code */
            // 添加账号
            cout << "申请预约" << endl;
            stu->applyOrder();
            system("pause");
            system("cls");
            break;
        case 2:
            // 查看账号
            cout << "查看自身预约" << endl;
            stu->showMyOrder();
            system("pause");
            system("cls");
            break;
        case 3:
            // 查看机房
            cout << "查看所有预约" << endl;
            stu->showAllOrder();
            system("pause");
            system("cls");
            break;
        case 4:
            // 清空预约
            cout << "取消预约" << endl;
            stu->cancelOrder();
            system("pause");
            system("cls");
            break;
        default:
            // 默认其他操作值为退出登陆
            delete stu; // 销毁堆区对象
            cout << "退出成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

void MenuMgr::showTeacherMenu(Identity *person)
{
    while (true)
    {
        // 调用子类的管理员的菜单
        person->operMenu();

        // 将父类指针转换成子类的指针
        Teacher *tea = dynamic_cast<Teacher *>(person);

        int select = 0;
        // 接收用户的选择
        cin >> select;
        switch (select)
        {
        case 1:
            /* code */
            cout << "查看所有预约" << endl;
            tea->showAllOrder();
            system("pause");
            system("cls");
            break;
        case 2:
            cout << "审核预约" << endl;
            tea->vaildOrder();
            system("pause");
            system("cls");
            break;
        default:
            // 默认其他操作值为退出登陆
            delete tea; // 销毁堆区对象
            cout << "退出成功" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}
