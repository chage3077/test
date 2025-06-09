#include "ShellSort.h"

void ShellSort::sort(vector<int>& nums)
{
	int h = 1;
	while (h < nums.size())
	{
		h = 2 * h + 1;
	}
	while (h >= 1)
	{
		for (int i = h; i < nums.size(); i++)
		{
			for (int j = i; j >= h; j -= h)
			{
				if (isGreater(nums[j - h], nums[j]))
				{
					swap(nums, j - h, j);
				}
				else
					break;
			}
		}
		h = h / 2;
	}
}

bool ShellSort::isGreater(int a, int b)
{
	return a > b;
}

void ShellSort::swap(vector<int>& nums, int i, int j)
{
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}
