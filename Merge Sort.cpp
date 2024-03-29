#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

constexpr int Threshold = 2;
void merge(vector<int>&arr,int p,int q,int r)
{
    int n1 = q - p + 1, n2 = r - q;//计算出子数列分别的长度
    vector<int>lhs(n1+1), rhs(n2+1);//创建左右数列
    int i, j;
    for (i = 0; i != n1; i++)
        lhs[i] = arr[p + i];
    for (j = 0; j != n2; j++)
        rhs[j] = arr[q + j + 1];//复制数列
    lhs[n1] = rhs[n2] = INT_MAX;//设置哨兵,标记已经为空的子数列
    i = j = 0;
    for (int k = p; k != r+1; k++)
    {
        if (lhs[i] <= rhs[j])arr[k] = lhs[i++];
        else arr[k] = rhs[j++];//将左右数列复制回原数列
    }
}

/*
*循环不变式:
*初始化:k=p,子数组无元素,包含了0个最小元素,lhs[i]与rhs[j]均为各自未被复制最小元素
*保持:每次迭代,k++,i/j++,更新数组,子数组包含了k-p+1个最小元素,lhs[i]与rhs[j]均为各自未被复制最小元素.
*终止:k=r+1,子数列包括了k-p=r-p+1个有序元素,lhs与rhs中除哨兵外均被复制
*/
/*
*Time complexity:O(n)
*Space complexity:O(n)
*/

void merge2(vector<int>&arr, int p, int q, int r)//无哨兵版本
{
    int n1 = q - p + 1, n2 = r - q;//计算出子数列分别的长度
    vector<int>lhs(n1), rhs(n2);//创建左右数列
    int i, j;
    for (i = 0; i != n1; i++)
        lhs[i] = arr[p + i];
    for (j = 0; j != n2; j++)
        rhs[j] = arr[q + j + 1];//复制数列
    i = j = 0;
    for (int k = p; k != r + 1; k++)
    {
        if (lhs[i] <= rhs[j])arr[k] = lhs[i++];
        else arr[k] = rhs[j++];//将左右数列复制回原数列
        if (i == n1)//子数组均被复制
            while (j != n2)arr[++k] = rhs[j++];//++k,目的是为了补偿原本的k++过程
        else if (j == n2)
            while (i != n1)arr[++k] = lhs[i++];
    }
}

void insertsort(vector<int>&arr, int l, int r) {
    for (int i = l + 1; i != r + 1; i++)
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

void mergesort(vector<int>&arr, int p, int r){
    if (p < r) {//若元素>=2
        int q = (p + r) / 2;//中位数
        if (r - p > Threshold)
        {
            mergesort(arr, p, q);//左侧数组归并排序
            mergesort(arr, q + 1, r);//右侧数组归并排序
            merge2(arr, p, q, r);//对左右数组分别归并
        }
        else insertsort(arr, p, r);//子问题最够小时,采取插入排序让递归的叶变粗,减少递归深度
    }
}
/*
*Time complexity:O(n)*递归深度(logn+1)=O(nlogn)
*Space complexity:O(n)
*/



int main()
{
    vector<int>arr{ 5,2,3,4,5,2,1,2,5,6,9,4,30 };
    mergesort(arr, 0, arr.size()-1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
    return 0;
}

