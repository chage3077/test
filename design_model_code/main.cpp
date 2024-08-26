#include <iostream>
#include <cstring>
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

void test03()
{
    
    cout << "What year was your house built?\n";
    int year;
    cin >> year; // 留下的回车换行符会留下在缓存区中
    //加上cin.get()把回车换行符捕获
    cin.get();
    cout << "What is its street address?\n";
    char address[80];
    // 由于缓存区中存在回车换行符，cin.getline()会把回车换行符认为是一串空字符串，把空字符串存到address中，所有用户输入不了
    cin.getline(address, 80); //79个字符加上'\0'
    cout << "Year built:" << year << endl;
    cout << "Address:" << address << endl;
    cout << "Done!\n";
}

void test04(){
    char charr[20]; // 只是一个char数组
    string str;
    cout << "Length of string in charr before input:" << strlen(charr) << endl; // 计算charr的字符数量，根据'\0'进行终止，对于char数组没进行赋值，会一直寻找'/0'
    cout << "Length of string in str before input:"<< str.size() << endl; // 计算str的字符数量
    cout << "Enter a line of text:\n";
    // indicate maximum length
    cin.getline(charr,20); // 输入读取整行charr，使用cin.getline读取20个字符
    cout << "You entered:"<<charr<< endl;
    cout << "Enter another line of text:\n";
    // cin now an argument;no length specifier
    
    getline(cin,str); // getline()是一个简单的函数，输入读取str，不能使用cin.getline(str,10)。因为cin.getline(char类型，读取字符数量)
    cout << "You entered:" << str << endl;
    cout << "Length of string in charr after input:"<< strlen(charr) << endl;
    cout << "Length of string in str after input:"<< str.size() << endl;
}
// 主函数入口
int main()
{
    test01();

    test02();

    //test03();

    test04();

    system("pause");

    return 0;
}