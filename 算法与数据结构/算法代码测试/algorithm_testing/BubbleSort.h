#pragma once
#include<iostream>
#include<vector>
using namespace std;
class BubbleSort
{
public:
	void static sort(vector<int>& v);
	bool static isGreater(int a, int b);
	void static swap(vector<int>& v,int a, int b);

	
};