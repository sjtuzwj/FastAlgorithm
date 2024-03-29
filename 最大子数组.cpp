#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

vector<int> findmaxcross(vector<int>&arr, int low, int mid, int high)
{
    int leftsum = INT_MIN;
    int sum = 0;
    int maxleft;
    for (int i = mid; i >= low; i--)//分别以mid为基点,求左右半边数组的最大值与最大边界
    {
        sum += arr[i];
        if (sum > leftsum)
        {
            leftsum = sum;
            maxleft = i;
        }
    }
    int rightsum = INT_MIN;
    sum = 0;
    int maxright;
    for (int i = mid+1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > rightsum)
        {
            rightsum = sum;
            maxright = i;
        }
    }
    return vector<int>{maxleft, maxright, leftsum + rightsum};
}

vector<int>findmaxarr(vector<int>&arr, int low, int high)
{
    if (high == low)
        return vector<int>{low, high, arr[low]};
    else {//比较三个数组的大小
        int mid = (low + high) / 2;
        auto left = findmaxarr(arr, low, mid);
        auto right = findmaxarr(arr, mid + 1, high);
        auto cross = findmaxcross(arr, low, mid, high);
        if (left[2] >= right[2] && left[2] >= cross[2])return left;
        else if (right[2] >= left[2] && right[2] >= cross[2])return right;
        else return cross;
    }
}
/*
*Time:O(nlgn)
*Space:O(nlgn)
*/

vector<int> Kadane(vector<int>&arr)//难于处理全为非正的情况
{
    int left=0,right=0,tmpleft=0, tmpright=0;
    int total = 0, max = INT_MIN;
    for (int i = 0; i!=arr.size(); i++)
    {
        total += arr[i];
        tmpright = i;
        if (total < 0) {//小于0,重新开始计算子数组
            total = 0;
            tmpleft = tmpright = i+1;
        }
        if (total > max) {//大于max,更新最大子数组
            max = total;
            left = tmpleft;
            right = tmpright;
        }
    }
    if(max>0)
    return vector<int>{left, right, max};
    else//元素均小于等于0,再次遍历求最大元素
    {
        int max = INT_MIN, site = 0;
        for (int i = 0; i != arr.size(); i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
                site = i;
            }
        }
        return vector<int>{site, site, max};
    }
}
/*
*Time:O(n)
*Space:O(1)
*/
int main()
{
    vector<int> arr{ -44,-5,-3,-2,-5,-52,-4,-3,-10 ,-15,-23,-40,-10,-32,-100};
    auto str= findmaxarr(arr,0,arr.size()-1);
    auto str2 = Kadane(arr);
    for (auto x : str)
        cout << x << " ";
    cout << endl;
    for (auto x : str2)
        cout << x << " ";
    return 0;
}

