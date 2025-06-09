#include "SelectionSort.h"

void SelectionSort::sort(vector<int>& nums)
{
    for (int i = 0; i <= nums.size() - 2; i++)
    {
        // 记录最小元素所在的索引，默认为每一轮排序的第一个位置
        int minIndex = i;
        // 从下一个元素开始比较
        for (int j = i + 1; j < nums.size(); j++)
        {
            // 比较minIndex和j的元素大小，如果j比minIndex小，则更新minIndex
            if (isGreater(nums[minIndex], nums[j]))
            {
                minIndex = j;
            }
        }
        // 每一轮结束后进行交换
        swap(nums, i, minIndex); // 传索引
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
