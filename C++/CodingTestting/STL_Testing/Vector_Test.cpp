#include"vector_test.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
Vector_Test::Vector_Test()
{
}

Vector_Test::~Vector_Test()
{
}
void Vector_Test::test_vector()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for_each(v.begin(), v.end(), myPrintf<int>);
}

void Vector_Test::test_vector_person()
{
    vector<Person> v;
    v.push_back(Person("张三", 18));
    v.push_back(Person("李四", 19));
    v.push_back(Person("王五", 20));

    // 遍历容器中的数据
    // 可把迭代器看成一个指针
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->name << "，年龄：" << it->age << endl;
        // 此时每个迭代器取出来的是数据对象，则*it是Person对象
        // cout << "姓名：" << (*it).name << "，年龄：" << (*it).age << endl;
    }
}

void Vector_Test::test_vector_person_address()
{
    vector<Person*> v;

    Person p1("Tom", 18);
    Person p2("Jerry", 16);
    Person p3("Mike", 19);
    Person p4("Lucy", 17);

    // 存放地址
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    // 遍历
    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 此时每个迭代器取出来的是指针，则*it是一个指向Person的指针
        cout << "姓名：" << (*it)->name << "，年龄：" << (*it)->age << endl;
    }
}

void Vector_Test::test_nested_vector()
{
    // 创建大容器
    vector<vector<int>> v;
    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 小容器添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    // 大容器添加小容器
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器遍历所有数据
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 此时(*it)代表的是一个小容器vector<int>
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}
