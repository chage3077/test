#include "ListSortExample.h"

void ListSortExample::createPerson()
{
	Person_sort p1("张小小", 175, 35);
	Person_sort p2("张中中", 180, 45);
	Person_sort p3("周笑", 170, 40);
	Person_sort p4("霍霍", 190, 25);
	Person_sort p5("张大大", 160, 35);
	Person_sort p6("张坤", 200, 35);

	m_PersonLists.push_back(p1);
	m_PersonLists.push_back(p2);
	m_PersonLists.push_back(p3);
	m_PersonLists.push_back(p4);
	m_PersonLists.push_back(p5);
	m_PersonLists.push_back(p6);
}

void ListSortExample::printf()
{
	for (list<Person_sort>::const_iterator it = m_PersonLists.begin(); it != m_PersonLists.end(); it++)
	{
		cout << "姓名：" << it->m_name << ",年龄：" << it->m_age << ",身高：" << it->m_height << endl;
	}
}

void ListSortExample::sortPerson()
{
	cout << "排序前......." << endl;
	printf();
	cout << "排序后......." << endl;
	m_PersonLists.sort(comparePerson);
	printf();
}
bool ListSortExample::comparePerson(Person_sort& p1, Person_sort& p2)
{
	// 高级排序
	if (p1.m_age == p2.m_age)
	{
		// 年龄相同的情况下，身高按照降序排序
		return p1.m_height > p2.m_height;
	}
	// 按照年龄升序
	return p1.m_age < p2.m_age;
}


