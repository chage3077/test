#include "TaskQuene.h"
// 静态变量在.h文件中声明，需要在.cpp文件进行定义，不能在.h文件进行定义，不然会报错“multiple definition”
TaskQuene* TaskQuene::m_taskQ = new TaskQuene;
mutex TaskQuene::m_mutex;

TaskQuene *TaskQuene::getInstance()
{
    return m_taskQ;
}
// 判断任务队列是否为空
bool TaskQuene::isEmpty()
{
    lock_guard<mutex>locker(m_mutex); // 利用lock_guard上锁，当locker析构的时候进行解锁
    bool flag = m_data.empty();
    return flag;
}
// 添加任务
void TaskQuene::addTask(int node)
{
    lock_guard<mutex>locker(m_mutex);
    m_data.push(node);
}
// 取数据
int TaskQuene::takeTask()
{
    lock_guard<mutex>locker(m_mutex);
    if(m_data.empty())
    {
        return -1;
    }
    int data = m_data.front(); // 获取队头的值
    return data;
}
// 删除任务
bool TaskQuene::popTask()
{
    lock_guard<mutex>locker(m_mutex);
    if(m_data.empty())
    {
        return false;
    }
    m_data.pop();
    return true;
}

