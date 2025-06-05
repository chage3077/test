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
		staff.m_name = string("Ա��") + str[i];
		staff.m_salary = rand() % 10000 + 10000;
		m_Staffs.push_back(staff);
	}
}

void StaffMgr::setGrounp()
{
	for (vector<Staff>::iterator it = m_Staffs.begin(); it != m_Staffs.end(); it++)
	{
		// ��������Ĳ��ű��
		int index = rand() % 3;
		it->m_deptId = index;
		// ����multimap
		m_StaffMap[index].push_back(*it);		
	}
	for (auto mit = m_StaffMap.begin(); mit != m_StaffMap.end(); mit++)
	{
		// н�ʴӴ�С����
		sort(mit->second.begin(), mit->second.end(), compareBySalary);
	}
}

void StaffMgr::showAllStaffs()
{
	string depatName[3] = { "����","�߻�","�з�" };
	// �ֲ��Ŵ�ӡ
	for (map<int, vector<Staff>>::iterator mit = m_StaffMap.begin(); mit != m_StaffMap.end(); mit++)
	{
		for (vector<Staff>::iterator it = mit->second.begin(); it != mit->second.end(); it++)
		{
			cout << "���ţ�" << depatName[mit->first] << "��������" << it->m_name << "��н�ʣ�" << it->m_salary << endl;
		}
	}
	

	
}

bool StaffMgr::compareBySalary(const Staff& a, const Staff& b)
{
	return a.m_salary > b.m_salary;
}
