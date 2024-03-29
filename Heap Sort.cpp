#include "stdafx.h"
#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;
inline int parent(int i) { return (i + 1) / 2 - 1; }
inline int left(int i) { return 2*i + 1; }
inline int right(int i) { return 2*i + 2; }
namespace
{
    int hp;
    template<typename T>
    void maxheapity(vector<T>&arr, int i)//要求:子节点均为最大堆的根节点
    {
        int l = left(i), r = right(i), largest;//寻找父节点,左右子节点中的最大值
        if (l < hp && arr[i] < arr[l])
            largest = l;
        else largest = i;
        if (r < hp && arr[largest] < arr[r])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);//父节点与最大值交换
            maxheapity(arr, largest);//重新构建交换后的子节点的最大堆
        }
    }
    //Time:O(lgn),Space:O(1)

    template<typename T>
    void buildmaxheapity(vector<T>&arr)//自底向下构建最大堆
    {
        hp = arr.size();
        for (int i = hp / 2 - 1; i >= 0; i--)
            maxheapity(arr, i);
    }
    /*
    *初始化:i=n/2,大于i的均为叶节点,为最大堆的根节点
    *保持:结点i维护了其后续均为最大堆的根节点,i--,为下一次循环重新建立循环不变量
    *终止:i=0,所有节点均为最大堆的根
    */
    //Time:O(n),Space:O(1)

    template<typename T>
    void buildmaxheapity2(vector<T>&arr)
    {
        hp = 1;
        for (unsigned  i = 1; i < arr.size(); i++)
        {
            maxheapinsert(arr, arr[i]);
        }
    }
    /*
    *初始化：仅有一个元素，显然为最大堆
    *保持：每次插入，都向上插入正确位置，保持最大堆
    *终止：i=arr.size(),所有节点均已插入，且为最大堆
    */
    //Time:O(nlogn),Space:O(1)(最优:只与父节点比较,最劣:每次均调整至根节点,其中平均调整长度logn/2,故最大复杂度nlogn)
    template<typename T>
    void heapsort(vector<T>&arr)
    {
        buildmaxheapity2(arr);
        for (int i = arr.size() - 1; i != 0; i--)
        {
            swap(arr[0], arr[i]);//将根节点(最大元素)交换到最末尾
            hp--;//元素脱离堆,已经有序,堆的有效元素-1
            maxheapity(arr, 0);//重新构造最大堆,求出最大元素
        }
    }
    //Time:O(nlgn),Space:O(1)

    template<typename T>
    T& heapmax(vector<T>&arr) { return arr[0]; }

    template<typename T>
    T heapextractmax(vector<T>&arr)//去除并返回队首
    {
        if (hp == 0) { exit("heap underflow"); }
        T max = arr[0];
        arr[0] = arr[hp - 1];//原arr[hp-1]处数据失效
        hp--;
        maxheapity(arr, 0);//重建最大堆
        return max;
    }
    //Time:o(lgn),Space:O(1)
    template<typename T>
    void heapincreasekey(vector<T>&arr, int i, T key)//将某个关键字变大
    {
        if (key < arr[i]) { cout << "new key is smaller than current key"; return; }
        while (i > 0 && arr[parent(i)] <= key)//迭代,直至找到第一个值大于key的元素
        {
            arr[i] = arr[parent(i)];//!!!插入排序思想,利用槽而非交换,层层下移
            i = parent(i);
        }
        arr[i] = key;//填入最后一个值小于等于key的元素
    }
    /*
    *初始化:arr[i]=key,此时若arr[i]>arr[parent],则满足第二法则,若<则满足第一法则
    *过程:若交换(必然为arr[i]>arr[parent]),arr[parent]变为最大堆根节点,i更新,满足循环不变量
    *终止:i=0,则已经将arr[0]变为最大堆根节点.或arr[parent]>arr[i],显然arr[parent]已为最大堆根节点,其父节点保持原样均满足最大堆的性质
    */
    //Time:o(lgn),Space:O(1)
    template<typename T>
    void maxheapinsert(vector<T>&arr, int key)//插入元素
    {
        hp++;
        arr[hp - 1] = INT_MIN;//扩展最大堆
        heapincreasekey(arr, hp-1, key);//设置新节点对应关键字
    }
    //Time:o(lgn),Space:O(1)

    template<typename T>
    void heapdelete(vector<T>&arr, int i)
    {
        T tmp = arr[i];
        arr[0] = arr[hp - 1];//原arr[hp-1]处数据失效
        hp--;
        maxheapity(arr, i);//重建最大堆
    }
    //Time:O(lgn),Space:O(1)


    //最小堆
    template<typename T>
    void minheapity(vector<T>&arr, int i)
    {
        int l = left(i), r = right(i), least;
        if (l<hp && arr[i]>arr[l])
            least = l;
        else least = i;
        if (r < hp && arr[least]>arr[r])
            least = r;
        if (least != i)
        {
            swap(arr[i], arr[least]);
            minheapity(arr, least);
        }
    }
    //Time:O(lgn),Space:O(1)
    template<typename T>
    void buildminheapity(vector<T>&arr)
    {
        hp = arr.size();
        for(int i = hp / 2 - 1; i >= 0; i--)
        minheapity(arr, i);
    }
    template<typename T>
    void heapmindelete(vector<T>&arr,int i)
    {
        T tmp = arr[i];
        arr[0] = arr[hp - 1];
        hp--;
        minheapity(arr, i);
    }
}
template<typename T>
list<T>mergelist(vector<list<T>>&link)//对有序链表进行归并,可读性暴低
{
    vector<pair<int,list<T>>>linkheap;//此处应当自己建立数据结构,采用存储指针的方法最佳
    list<T>res;
    for (auto x : link)
        if(x.size())
            linkheap.push_back(make_pair(x.front(),x));//添加链表首与链表的对组
    buildminheapity(linkheap);//建立最小堆
    while (hp)
    {
        auto& tmp = linkheap.front();//取出链表首最小的链表
        res.push_back(tmp.first);//添加最小元素至新链表
        tmp.second.pop_front();//删除原最小元素
        if(tmp.second.size())//不加此判断,出现list iterator not dereferencable ERROR
            tmp.first = tmp.second.front();//更新链表首
        if (tmp.second.empty())
            heapmindelete(linkheap, 0);//当链表为空时,退出堆
        minheapity(linkheap, 0);//重建最小堆
    }
    return res;
}
//分析时间复杂度:建数组 时间:O(k)
//建立最小堆:时间:O(k)
//添加并删除元素:时间:O(n)
//调整最小堆:O(lgk)*n次(链表最后才为空,故每次时间复杂度均为lgk)
//Time :O(nlgk)
int main()
{
    vector<int>arr{ 9,29,3,2,-5,0,21,231 };
    heapsort(arr);
    cout << "This is heap sort: ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "This is mergelist: ";
    vector<list<int>>link{ { 1,5,11,15 }, { 3,4,12 },{4,5,6,7},{} };
    auto res=mergelist(link);
    for (auto x : res)
        cout << x << " ";
    return 0;
}

