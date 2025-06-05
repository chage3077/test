#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define MEISHU 0
#define CEHUA 1
#define YANFA 2
using namespace std;

class Staff
{
public:
	string m_name;
	int m_salary;
	int m_deptId;

	Staff();
	Staff(string name, int salary, int depId) :m_name(name), m_salary(salary), m_deptId(m_deptId)
	{

	}
};
class StaffMgr
{
private:
	vector<Staff> m_Staffs;
	map<int, vector<Staff>> m_StaffMap;
public:
	void createStaff();
	void setGrounp();
	void showAllStaffs();
	static bool compareBySalary(const Staff& a, const Staff& b);
};
