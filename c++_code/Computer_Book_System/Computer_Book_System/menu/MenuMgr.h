#ifndef MENUMGR_H
#define MENUMGR_H
#include<iostream>
class Identity;

class MenuMgr
{
public:
    MenuMgr();
    void showMainMenu();
    void showManagerMenu(Identity* person); // 管理员子菜单
    void showStudentMenu(Identity* person); // 学生子菜单
};
#endif