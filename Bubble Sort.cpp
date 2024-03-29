// Bubble Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<array>
using namespace std;
constexpr int MAXN = 10;
void bubbleSort(array<int, MAXN>&arr)
{
	int tmp;
	bool flag;
	for (int i = 0; i != MAXN-1; i++)
	{
		flag = true;
		for (int j = 0; j != MAXN-1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag)break;
	}
}
/*
*外层循环不变式:
*初始化:i=0,左侧无元素,显然有序
*保持:每次迭代,均令最大的元素到达MAXN-1-i的位置,下标MAXN-1-i至MAXN-1数组有序
*终止:i=MAXN-1,则下标0至MANN-1数组有序
*/
/*
*内层循环不变式:
*初始化:j=0,不存在大小比较关系
*保持:每次迭代,令较小的元素到左侧,较大的元素到右侧,从而实现了arr[j+1]为当前最大元素
*终止:j=MAXN-1-i,arr[MAXN-1-i]为子数列中最大的元素
*/
/*
*Time complexity:O(n^2)/O(n)
*Space complexity:O(1)
*/
int main()
{
	array<int, MAXN>arr{ 10, 9, 8, 8, 6, 5, 4, 3, 2, 1 };
	bubbleSort(arr);
	for (auto x : arr)cout << x<<" ";
	return 0;
}

