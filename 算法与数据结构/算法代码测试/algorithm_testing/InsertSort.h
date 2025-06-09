#pragma once
#include<iostream>
#include<vector>
using namespace std;
class InsetSort
{
public:
    void static sort(vector<int>& nums);
    bool static isGreater(int a, int b);
    void static swap(vector<int>& nums, int i, int j);
};