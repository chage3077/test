#include"Recorder.h"
void Recorder::addHistory(int index,History* history)
{
    m_historyMap.insert(make_pair(index,history));
    // 写入磁盘文件
    // ...........
}

History *Recorder::getHistory(int index)
{
    if(m_historyMap.find(index)!=m_historyMap.end())
    {
        return m_historyMap[index];
    }
    return nullptr;
}
