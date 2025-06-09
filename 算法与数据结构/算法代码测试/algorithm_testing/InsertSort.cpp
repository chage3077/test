#include "InsertSort.h"

void InsetSort::sort(vector<int>& nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        // �����������������
        for (int j = i; j > 0; j--)
        {
            if (isGreater(nums[j - 1], nums[j]))
            {
                // ����j-1λ�õ�Ԫ�ش�������jλ�õ�Ԫ�أ�����λ��
                swap(nums, j, j - 1);
            }
            else
                // ������j-1λ�õ�Ԫ��С������jλ�õ�Ԫ�أ�˵��������ʵ�λ�ã����˳��ڲ�ѭ��
                break;
        }
    }
}

bool InsetSort::isGreater(int a, int b)
{
    return a > b;
}

void InsetSort::swap(vector<int>& nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
