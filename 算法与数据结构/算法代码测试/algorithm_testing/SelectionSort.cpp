#include "SelectionSort.h"

void SelectionSort::sort(vector<int>& nums)
{
    for (int i = 0; i <= nums.size() - 2; i++)
    {
        // ��¼��СԪ�����ڵ�������Ĭ��Ϊÿһ������ĵ�һ��λ��
        int minIndex = i;
        // ����һ��Ԫ�ؿ�ʼ�Ƚ�
        for (int j = i + 1; j < nums.size(); j++)
        {
            // �Ƚ�minIndex��j��Ԫ�ش�С�����j��minIndexС�������minIndex
            if (isGreater(nums[minIndex], nums[j]))
            {
                minIndex = j;
            }
        }
        // ÿһ�ֽ�������н���
        swap(nums, i, minIndex); // ������
    }
}

bool SelectionSort::isGreater(int a, int b)
{
	return a > b;
}

void SelectionSort::swap(vector<int>& nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
