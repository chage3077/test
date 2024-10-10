#ifndef FACTORY_H
#define FACTORY_H
#include"Animal.h"
enum class Type:char{Cat,Dog}; // 强类型枚举类型，指定在底层存储类型为char
class Factory // 工厂类父类
{
private:
    /* data */
public:
    Factory(){}
    virtual ~Factory(){}
    // 简单工厂模式
    // Animal* createAnimal(Type type); // 多态处理，返回父类指针
    // 工厂模式  创建对象接口
    virtual Animal* createAnimal()=0;
};
#endif