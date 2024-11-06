#ifndef ITERATORLIST_H
#define ITERATORLIST_H
#include"MyList.h"
// 迭代器基类，可以派生不同的方式遍历链表
class IteratorList
{
private:
    /* data */
protected:
    MyList* m_list = nullptr; // 记录需要遍历的链表
    Node* m_current = nullptr; // 记录当前的节点
public:
    IteratorList(MyList* list):m_list(list){};
    Node* getCurrent();
    virtual Node* first() = 0 ; // 访问当前链表的头节点
    virtual Node* next() = 0; // 遍历
    virtual bool isDone()=0; // 判断链表是否遍历完
    virtual ~IteratorList(){};
};
#endif