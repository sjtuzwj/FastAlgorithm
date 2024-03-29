#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

int binarysearch(vector<int>&arr,int beg, int end, int value)
{
    if (beg == end)return -1;//未查找到
    int mid = (beg + end) / 2;//中位数
    if (value < arr[mid])return binarysearch(arr, beg, mid, value);//左半区间
    else if (value > arr[mid])return binarysearch(arr, mid + 1, end, value);//右半区间
    else return mid;//查找到
}
/*
*Time complexity:O(logn)
*Space cpmplexity:O(logn)
*/
int main()
{
    vector<int>arr{ 1,2,3,4,6,7,8,9,11 };
    cout<<binarysearch(arr, 0, arr.size() - 1, 9);
    return 0;
}

