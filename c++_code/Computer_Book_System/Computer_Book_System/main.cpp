#include "MenuMgr.h"
#include <iostream>
#include "LoginManager.h"
#include "globalFile.h"
#include "Windows.h"
#include <thread>
#include <chrono>
using namespace std;
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // 设置控制台输入为 UTF-8
    SetConsoleCP(CP_UTF8);

   // 让当前线程休眠 5 秒
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    int select = 0;
    MenuMgr *menuMgr = new MenuMgr();
    LoginManager loginManager;
    while (true)
    {
        menuMgr->showMainMenu();
        cin >> select; // 接收选择

        switch (select)
        {
        case 1: // 学生
            /* code */
            loginManager.login(STUDENT_FILE, 1, menuMgr);
            break;
        case 2: // 老师
            loginManager.login(TEACHER_FILE, 2, menuMgr);
            break;
        case 3: // 管理员
            loginManager.login(ADMIN_FILE, 3, menuMgr);
            break;
        case 4: // 退出
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
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