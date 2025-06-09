#include"BubbleSort.h"
void BubbleSort::sort(vector<int>& v)
{
    // 初始化每个元素都参与冒泡排序，随后参与冒泡元素减少
    // 至少有一个元素参与冒泡排序
    // 确定冒泡排序的轮数
    for (int i = v.size() - 1; i > 0; --i)
    {
        // 每一轮冒泡排序的次数
        for (int j = 0; j < i; ++j)
        {
            // 比较相邻的两个元素，若j的元素大于j+1的元素，则交换位置
            if (isGreater(v[j], v[j + 1]))
            {
                swap(v,j,j+1); // 交换位置
            }
        }
    }
    
}
bool BubbleSort::isGreater(int a, int b)
{
    return a > b;
}
void BubbleSort::swap(vector<int>&v,int a, int b)
{
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}
