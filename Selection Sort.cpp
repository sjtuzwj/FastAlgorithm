#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;
void selectionsort(vector<int>&arr)
{
    for (int i = 0; i != arr.size() - 1; i++)
    {
        int mini=i, tmp;
        for (int j = i+1; j != arr.size(); j++)
        {
            mini =arr[j]>arr[mini]?mini:j;
        }
        tmp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = tmp;
    }
}

/*
*循环不变式:
*初始化:i=0,左侧无元素,显然有序
*保持:每次迭代,均令第i+1小的元素到达下标i的位置,下标0至i数组有序
*终止:i=length-1,则下标0至length-1数组有序,进而0至length数组有序
*/
/*
*Time complexity:O(n^2)/O(n^2)
*Space complexity:O(1)
*/
int main()
{
    vector<int>arr{ 1,5,23,4,5,2,3,4,9 };
    selectionsort(arr);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}

