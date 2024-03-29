#include<vector>
#include<string>
#include<iostream>
using namespace std;
template<typename T>
void quicksort(vector<T>&v, int left, int right)//支持比较运算符
{
	if (left < right) {//区间存在且需要排序
		T key = v[left];//基数
		int low = left;
		int high = right;
		while (low < high) {
			while (low < high&&key <= v[high])high--;//high下标开始，向左遍历，查找小于基数的元素
			if (low < high) //存在小于基数的元素
				v[low++] = v[high];//赋值给low下标位置，low下标后移
			while (low < high&&v[low] < key)low++;//low下标开始，向右遍历，查找不小于基数的元素
			if (low < high) //存在不小于基数的元素
				v[high--] = v[low];//赋值给high下标位置，high下标前移
		}
		v[low] = key;
		quicksort(v, left, low - 1);
		quicksort(v, low + 1, right);
	}
}
int main()
{
	vector<int>itarr{ 4,3,5,2,6,1 };
	vector<string>starr{ "str","arr","battle","thanks","here" };
	quicksort(itarr, 0, itarr.size() - 1);
	quicksort(starr, 0, starr.size() - 1);
	for (auto x : itarr)cout << x<<endl;
	for (auto x : starr)cout << x<<endl;
	return 0;
}

