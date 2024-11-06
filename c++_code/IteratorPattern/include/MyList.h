#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
#include <string>
using namespace std;
// 类声明
class IteratorList; // 这样避免出现头文件嵌套包含定义，只是使用到该类型，不使用内部的成员变量和方法
// 链表最小存储单位——节点
struct Node
{
    /* data */
    Node(string data) : m_data(data) {}; // 初始化节点，顺便存储数据
    Node *m_prev = nullptr;              // 指向前驱节点
    Node *m_next = nullptr;              // 指向后继节点
    string m_data = string();            // 存储数据
};

// 存储数据的链表——双向列表
class MyList
{
private:
    /* data */
    Node *m_hand = nullptr; // 头节点
    Node *m_tail = nullptr; // 尾结点
    int m_count = 0;        // 获取节点数量
public:
    // 获取节点数量——内联函数，以空间换时间，快速执行代码
    inline int getCount()
    {
        return m_count;
    }
    // 获取头节点
    inline Node *getHand()
    {
        return m_hand;
    }
    // 获取尾节点
    inline Node *getTail()
    {
        return m_tail;
    }

    // 插入数据
    Node *insertNode(Node *node, string data); // 中间插入链表
    Node *insertFront(string data);            // 头部插入数据
    Node *insertTail(string data);             // 尾部插入数据

    // 获取对应的迭代器
    IteratorList *getIterator(bool isReverse = true);

    // 释放内存
    ~MyList();
};
#endif