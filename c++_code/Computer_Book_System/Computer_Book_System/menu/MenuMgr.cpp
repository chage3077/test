#include "MenuMgr.h"
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
    cout << "\t\t---------------------------------\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  1.学生代表                    |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  2.老师                       |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  3.管理员                     |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t|  4.退出                        |\n";
    cout << "\t\t|                               |\n";
    cout << "\t\t---------------------------------\n";
    cout << "输入你的选择：" << endl;
}