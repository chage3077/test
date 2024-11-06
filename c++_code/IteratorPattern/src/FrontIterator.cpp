#include "FrontIterator.h"

Node *FrontIterator::first()
{
    // 获取头部节点
    m_current = m_list->getHand();
    return m_current;
}

Node *FrontIterator::next()
{
    // 节点向后走
    m_current = m_current->m_next;
    return m_current;
}

bool FrontIterator::isDone()
{
    // 判断是否遍历结束
    if (m_current == m_list->getTail()->m_next)
        return true;
    else
        return false;
}
