#ifndef DIRECTOR_H
#define DIRECTOR_H
#include<iostream>
#include"HouseBuilder.h"
// 包工头
class Director
{
public:
    void setBuilder(HouseBuilder* builder);
    // 创建不同的房型
    void buildJingjiXing();
    void buildBiaoZhunXing();
    void buildHaohuaXing();
private:
    HouseBuilder* m_builder;
};
#endif