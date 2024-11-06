#include "MyList.h"
#include "FrontIterator.h"
#include "BackIterator.h"
Node *MyList::insertNode(Node *node, string data)
{
    Node *item = nullptr;
    if (node == m_hand) // 判断要插入的地方是否为头节点
    {
        item = insertFront(data);
    }
    else // 在中间插入
    {
        item = new Node(data);
        // 1.将item链接到链表中
        item->m_next = node;
        item->m_prev = node->m_prev;
        // 断开node的连接
        node->m_prev->m_next = item;
        node->m_prev = item;
        // 数量加1
        m_count++;
    }
    return item;
}

Node *MyList::insertFront(string data)
{
    Node *node = new Node(data); // 创建新节点
    // 先判断头节点是否为空——空链表
    if (m_hand == nullptr)
    {
        m_hand = node;
        m_tail = node;
    }
    else
    {
        node->m_next = m_hand; // 新节点node后继是旧的头节点
        m_hand->m_prev = node; // 更新旧的头节点前驱
        m_hand = node;         // 更新头节点
    }
    m_count++;
    return node;
}

Node *MyList::insertTail(string data)
{
    Node *node = new Node(data); // 创建新节点
    if (m_hand == nullptr)
    {
        m_hand = node;
        m_tail = node;
    }
    else
    {
        m_tail->m_next = node;
        node->m_prev = m_tail;
        m_tail = node;
    }
    m_count++;
    return node;
}

IteratorList *MyList::getIterator(bool isReverse)
{
    IteratorList *it = nullptr;
    // 根据当前是否需要逆向遍历来创建对应的迭代器
    if (isReverse == true)
    {
        it = new BackIterator(this);
    }
    else
    {
        it = new FrontIterator(this);
    }
    return it;
}

MyList::~MyList()
{
    Node *t_ptr = nullptr;
    if (m_hand != nullptr)
    {
        t_ptr = m_hand;
        while (t_ptr != nullptr)
        {
            Node *qtr = t_ptr;
            t_ptr = t_ptr->m_next;
            delete qtr;
        }
    }
    delete t_ptr;
}
