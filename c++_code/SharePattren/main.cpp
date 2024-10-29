#include "BoomBodyFactory.h" // 静态数据
#include "LunchBoom.h"       // 动态数据
#include <vector>
int main()
{
    BoomBodyFactory *factory = new BoomBodyFactory;
    // 炮弹容器，放若干个炮弹
    vector<LunchBoom *> boomList;
    // 型号与数量
    vector<string> nameList = {"S1", "S1", "S2", "S2", "X1", "X1", "X1"};
    for (auto name : nameList) // 遍历型号容器，创建动态炮弹
    {
        int x = 0;
        int y = 0;
        // 工厂获取共享弹体后创建动态炮弹
        LunchBoom *boom = new LunchBoom(factory->getSharedData(name, "beautiful boom"));
        // 随机坐标
        for (int i = 0; i < 3; i++)
        {
            x += rand() % 100;
            y += rand() % 75;
            boom->move(x, y);
        }
        boomList.push_back(boom);
    }

    // 彩蛋静态资源
    UniqueBoomBody *caidan = new UniqueBoomBody("Big suprise", "caidan");
    // 创建动态资源
    LunchBoom *boom = new LunchBoom(caidan);
    int x = 0;
    int y = 0;
    // 随机坐标
    for (int i = 0; i < 3; i++)
    {
        x += rand() % 100;
        y += rand() % 75;
        boom->move(x, y);
    }
    boomList.push_back(boom); // 存入boomlist列表

    // 释放内存
    for (auto &item : boomList)
    {
        delete item;
    }
    delete caidan;
    delete factory;

    return 0;
}