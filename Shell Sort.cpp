#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
template<typename T>
void shellsort(vector<T>& arr)
{
    int N = arr.size();
    int h = 1;
    while (h < N / 3)h = 3 * h + 1;//先将h递增至合适值
    while (h >= 1) {//h间隔逐渐减小
        for (int i = h; i < N; i++)
        {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)//先进行子数组的排序
                swap(arr[j] , arr[j - h]);
        }
        h /= 3;
    }
}

int main()
{
    vector<int>arr{ 5,3,2,1,4,10,2,3 };
    shellsort(arr);
    for (auto x : arr)cout << x;
    return 0;
}

