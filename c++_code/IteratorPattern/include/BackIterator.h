#ifndef BACKITERATOR_H
#define BACKITERATOR_H
#include "IteratorList.h"
// 正向遍历迭代器
class BackIterator : public IteratorList
{
private:
    /* data */
public:
    using IteratorList::IteratorList; // 继承父类构造函数
    Node *first() override;           // 访问当前链表的头节点
    Node *next() override;            // 遍历
    bool isDone() override;           // 判断链表是否遍历完
};
#endif