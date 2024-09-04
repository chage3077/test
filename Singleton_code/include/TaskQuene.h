#ifndef TASKQUENE_H
#define TASKQUENE_H
#include <iostream>
#include <queue> // 队列头文件
#include <mutex> // 使用互斥锁
using namespace std;
// 单例模式中的饿汉模式
// 多线程访问单例对象内部数据的时候也存在多线程问题，内部数据共享资源的问题
class TaskQuene
{
public:
    static TaskQuene *getInstance();
    // 判断任务队列是否为空
    bool isEmpty();
    // 向任务队列添加任务
    void addTask(int node);
    // 向队列中取出任务
    int takeTask();
    // 删除队列的任务
    bool popTask();

private:
    TaskQuene() = default;
    TaskQuene(const TaskQuene &) = default;
    TaskQuene &operator=(const TaskQuene &t) = default;

    // 静态属性
    static TaskQuene *m_taskQ;
    // 队列成员变量
    queue<int> m_data; // 存储的数据是Int类型，需要保护共享数据
    static mutex m_mutex; // 互斥锁保护数据

};

#endif