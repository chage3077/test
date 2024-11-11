#ifndef NEWSAGENCY_H
#define NEWSAGENCY_H
#include <iostream>
#include <string>
#include <list>
using namespace std;
// 声明订阅者
class Observer;
// 定义报社（发布者）基类
class NewsAgency
{
private:
    /* data */
protected:
    list<Observer *> m_observer; // list相当于一个链表，频繁读取数据效率高。vector相当是动态数组，对于删除增加时效率没有list高

public:
    // 添加订阅者
    void attach(Observer *observer);
    // 删除订阅者
    void detach(Observer *Observer);
    // 发布消息
    virtual void notify(string msg) = 0;
    virtual ~NewsAgency() {}
};
#endif