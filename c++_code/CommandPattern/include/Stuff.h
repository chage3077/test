#ifndef STUFF_H
#define STUFF_H
#include "AbstructCommand.h"
#include <iostream>
#include <string>
#include <list>
#include <map>
class Stuff
{
private:
    /* data */
    map<int, list<AbstructCommand *>> m_cmdMap; // 记录该桌客人点的菜，结账后要清空该容器

public:
    void setOrder(int index, AbstructCommand *command);    // 点菜（任务队列）
    void deleteOrder(int index, AbstructCommand *command); // 撤销菜单
    void checkOut(int index);                              // 结账
    void notify(int index);                                // 调用命令，让厨师执行命令
};
#endif