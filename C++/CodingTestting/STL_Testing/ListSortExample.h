#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;
class Person_sort
{
public:
	string m_name;
	int m_height;
	int m_age;

	Person_sort(string name,int height,int age):m_name(name),m_height(height),m_age(age){}
};
class ListSortExample
{
public:
	list<Person_sort>m_PersonLists;
	void createPerson();
	void printf();
	void sortPerson(); // ��������
	static bool comparePerson(Person_sort &p1, Person_sort &p2); // �����Զ������͵�list������Ҫ�ƶ��ص�����ȷ���ȽϹ���
};

