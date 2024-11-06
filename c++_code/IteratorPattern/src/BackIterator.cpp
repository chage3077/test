#include "BackIterator.h"

Node *BackIterator::first()
{
    // 获取第一个几点，逆序遍历链表的第一个节点就是尾节点
    m_current = m_list->getTail();
    return m_current;
}

Node *BackIterator::next()
{
    // 节点往前移
    m_current = m_current->m_prev;
    return m_current;
}

bool BackIterator::isDone()
{
    if (m_current == m_list->getHand()->m_prev)
        return true;
    else
        return false;
}
