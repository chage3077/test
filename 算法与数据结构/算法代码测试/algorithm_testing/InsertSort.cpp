#include "InsertSort.h"

void InsetSort::sort(vector<int>& nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        // 倒叙遍历已排序序列
        for (int j = i; j > 0; j--)
        {
            if (isGreater(nums[j - 1], nums[j]))
            {
                // 索引j-1位置的元素大于索引j位置的元素，交换位置
                swap(nums, j, j - 1);
            }
            else
                // 若索引j-1位置的元素小于索引j位置的元素，说明到达合适的位置，则退出内层循环
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
