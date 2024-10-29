#include "BoomBodyFactory.h"
FlyWeightBody *BoomBodyFactory::getSharedData(string name, string spirt)
{
    FlyWeightBody *data = nullptr;
    // 遍历容器
    for (auto &item : m_sharedDataMap)
    {
        if (item.first == name)
        {
            // 找到该享元内存
            data = item.second; // 获取该内存
            cout << name << "Is using....." << endl;
            break;
        }
    }
    if (data == nullptr) // 说明没有开启该型号的享元内存
    {
        // 开辟该内存
        data = new SharedBoomBody(name, spirt);
        cout << "Don`t have.......creating.........." << name << "OK" << endl;
        // 保存到map中
        m_sharedDataMap.insert(make_pair(name, data));
    }

    return data;
}

BoomBodyFactory::~BoomBodyFactory()
{
    // 析构map
    for (auto &item : m_sharedDataMap)
    {
        delete item.second;
    }
}
