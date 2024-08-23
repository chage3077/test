#include <iostream>
#include "Association.h"
#include "Generalization.h"
// 测试继承关系，多态
void test01()
{
    // 创建父类指针并且指向子类
    Animal *ptr = new Dog();
    // 调用子类里重写的函数
    ptr->speak();
}

// 测试关联关系
void test02()
{
    // 创建汽车、人对象
    Car car1("Toyota");
    Person p1("The_Shy", &car1);
    p1.showPerson();
}
// 主函数入口
int main()
{
    test01();

    test02();

    system("pause");

    return 0;
}