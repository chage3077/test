#ifndef LOGINMANAGER_H
#define LOGINMANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include "MenuMgr.h"
using namespace std;
class LoginManager
{
private:
    /* data */
    Identity *m_person; // 父类指针
public:
    LoginManager(/* args */);
    ~LoginManager();

    void login(string filename, int type, MenuMgr *menuMgr); // 登陆函数
};
#endif