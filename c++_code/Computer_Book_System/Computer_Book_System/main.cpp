#include "MenuMgr.h"
#include <iostream>
using namespace std;
int main()
{
    int select = 0;
    MenuMgr menuMgr;
    while (true)
    {
        menuMgr.showMainMenu();
        cin >> select; // 接收选择

        switch (select)
        {
        case 1: // 学生
            /* code */
            break;
        case 2: // 老师
            break;
        case 3: // 管理员
            break;
        case 4: // 退出
            break;
        default:
            cout << "请重新选择" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}