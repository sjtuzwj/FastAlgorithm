
#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

void insertsort(vector<int>&arr) {
    for (int i = 1; i != arr.size(); i++)
    {
        int key = arr[i];//正在被插入的数
        int j = i - 1;//左侧有序数组的末尾
        while (j >= 0 && arr[j] > key)//向左遍历,直至最后一个大于被插入数元素(即正确位置)的左侧一位
        {
            arr[j + 1] = arr[j];//正确位置右侧全部右移一个offset,将槽填补,并且在正确位置留下空槽
            j--;//向左遍历
        }
        arr[j + 1] = key;//填补空槽
    }
}
/*
*循环不变式:
*初始化:i=1,左侧仅一个元素,显然有序
*保持:每次迭代,均找到正确位置,下标0至i数组有序
*终止:i=arr.size(),则下标0至arr.size()-1数组有序
*/
/*
*Time complexity:O(n^2)/O(n)
*Space complexity:O(1)
*/
int main()
{
    vector<int>arr{ 5,4,3,5,2,4,9,8,5,3,2 };
    insertsort(arr);
    for (auto x : arr)
    {
        cout << x<< ' ';
    }
    return 0;
}

