#include"BubbleSort.h"
void BubbleSort::sort(vector<int>& v)
{
    // ��ʼ��ÿ��Ԫ�ض�����ð������������ð��Ԫ�ؼ���
    // ������һ��Ԫ�ز���ð������
    // ȷ��ð�����������
    for (int i = v.size() - 1; i > 0; --i)
    {
        // ÿһ��ð������Ĵ���
        for (int j = 0; j < i; ++j)
        {
            // �Ƚ����ڵ�����Ԫ�أ���j��Ԫ�ش���j+1��Ԫ�أ��򽻻�λ��
            if (isGreater(v[j], v[j + 1]))
            {
                swap(v,j,j+1); // ����λ��
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
