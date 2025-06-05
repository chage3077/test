#include "StaffMgr.h"

Staff::Staff()
{
}
void StaffMgr::createStaff()
{
	string str = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Staff staff;
		staff.m_name = string("员工") + str[i];
		staff.m_salary = rand() % 10000 + 10000;
		m_Staffs.push_back(staff);
	}
}

void StaffMgr::setGrounp()
{
	for (vector<Staff>::iterator it = m_Staffs.begin(); it != m_Staffs.end(); it++)
	{
		// 产生随机的部门编号
		int index = rand() % 3;
		it->m_deptId = index;
		// 放入multimap
		m_StaffMap[index].push_back(*it);		
	}
	for (auto mit = m_StaffMap.begin(); mit != m_StaffMap.end(); mit++)
	{
		// 薪资从大到小排序
		sort(mit->second.begin(), mit->second.end(), compareBySalary);
	}
}

void StaffMgr::showAllStaffs()
{
	string depatName[3] = { "美术","策划","研发" };
	// 分部门打印
	for (map<int, vector<Staff>>::iterator mit = m_StaffMap.begin(); mit != m_StaffMap.end(); mit++)
	{
		for (vector<Staff>::iterator it = mit->second.begin(); it != mit->second.end(); it++)
		{
			cout << "部门：" << depatName[mit->first] << "，姓名：" << it->m_name << "，薪资：" << it->m_salary << endl;
		}
	}
	

	
}

bool StaffMgr::compareBySalary(const Staff& a, const Staff& b)
{
	return a.m_salary > b.m_salary;
}
