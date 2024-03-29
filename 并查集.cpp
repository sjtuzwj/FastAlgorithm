#include<vector>
#include<iostream>
using namespace std;
//使用路径压缩的加权quick-union算法
class unionfind
{
private:
    vector<int> id;//根节点
    vector<int> weight;//权值
    int count;//分量数量
public:
    unionfind(int n);
    bool isconnected(int p, int q);
    int tot_count();
    int find(int p);
    void unionset(int p, int q);

};
unionfind::unionfind(int n)
{
    count = n;
    for (int i = 0; i < n; i++)
    {
        id.push_back(i);//初始时,根节点均为自己
        weight.push_back(1);
    }
}
bool unionfind::isconnected(int p, int q) {
    return find(p) == find(q);
}
int unionfind::tot_count() { return count; }
int unionfind::find(int p)
{
    vector<int>way{p};
    while (p != id[p]) {
        p = id[p];
        way.push_back(p);
    }//寻找根节点并记录路径上所有节点
    for (auto& x : way) {
        id[x] = p;
    }//路径压缩
    return p;
}
void unionfind::unionset(int p, int q)
{
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq)return;
    //将权值较少的树归并到权值大的树上
    if (weight[rootp] < weight[rootq]) { id[rootp] = rootq; weight[rootq] += weight[rootp]; }
    else { id[rootq] = rootp; weight[rootp] += weight[rootq]; }
    count--;//分量树-1;
}

int main()
{
    unionfind demo(10);
    demo.unionset(1, 5);
    demo.unionset(5, 2);
    demo.unionset(2, 7);
    demo.unionset(3, 7);
    cout << boolalpha << demo.isconnected(1, 3);
    return 0;
}

