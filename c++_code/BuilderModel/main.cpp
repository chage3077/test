#include"Director.h"
#include"FanDouXiaoqu.h"
#include"FanDouBuilder.h"
#include"NanYangXiaoqu.h"
#include"NanYangBuilder.h"
void buildFandou()
{
    // 创建包工头进行创建
    Director* director = new Director;

    FanDouBuilder* builder = new FanDouBuilder;
    // 绑定建造者
    director->setBuilder(builder);
    // 经济型房子
    director->buildJingjiXing();
    // 查看房型
    FanDouXiaoqu* houses = builder->getXiaoqu();
    houses->showHouses();
    delete houses;
    
    // 标准型房子
    builder->reset(); // 由于前面已经删除了，现在要重新创建一个FanDouXiaoqu指针
    director->buildBiaoZhunXing();
    houses = builder->getXiaoqu();
    houses->showHouses();
    delete houses;

    // 豪华型房子
    builder->reset();
    director->buildHaohuaXing();
    houses = builder->getXiaoqu();
    houses->showHouses();
    delete houses;

    delete director;
    delete builder;
}
void buildNanYang()
{
    // 创建包工头进行创建
    Director* director = new Director;

    NanYangBuilder* builder = new NanYangBuilder;
    // 绑定建造者
    director->setBuilder(builder);
    // 经济型房子
    director->buildJingjiXing();
    // 查看房型
    NanYangXiaoqu* houses = builder->getXiaoqu();
    houses->showHouses();
    delete houses;
    
    // 标准型房子
    builder->reset(); // 由于前面已经删除了，现在要重新创建一个FanDouXiaoqu指针
    director->buildBiaoZhunXing();
    houses = builder->getXiaoqu();
    houses->showHouses();
    delete houses;

    // 豪华型房子
    builder->reset();
    director->buildHaohuaXing();
    houses = builder->getXiaoqu();
    houses->showHouses();
    delete houses;
}
int main()
{
    buildFandou();
    cout<<"----------------------------------"<<endl;
    buildNanYang();
}