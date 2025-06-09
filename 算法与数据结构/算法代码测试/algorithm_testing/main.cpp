#include"BubbleSort.h"
#include"SelectionSort.h"
#include"InsertSort.h"
#include"ShellSort.h"
using namespace std;
void printf(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
	cout << "1.1����ð������" << endl;
	vector<int> v = { 3,2,6,1,5,4 };
	printf(v);
	BubbleSort::sort(v); // ����ð������
	printf(v); // ������


	cout << "1.2����ѡ������" << endl;
	vector<int> v1 = { 3,2,6,1,5,4,9,7,8 };
	printf(v1);
	SelectionSort::sort(v1);
	printf(v1);

	cout << "1.3���Բ�������" << endl;
	vector<int> v2 = { 4,3,2,10,12,1,5,6 };
	printf(v2);
	SelectionSort::sort(v2);
	printf(v2);

	cout << "2.1����ϣ������" << endl;
	vector<int> v3 = { 9,1,2,5,7,4,8,6,3,5 };
	printf(v3);
	ShellSort::sort(v3);
	printf(v3);

	system("pause");
	return 0;
}