#include<list>
#include<string>
#include<iostream>
using namespace std;
//MTF变换的作用是为频繁重复的输入符号提供较低的索引（数据压缩）
int main()
{
    string str;
    list<char>MoveToFront;
    cin >> str;
    for (size_t i=0;i<str.size();i++)
    {
        MoveToFront.remove_if([&](char& ch) {return ch == str[i]; });
        MoveToFront.push_front(str[i]);
    }
    for (auto& x: MoveToFront)cout << x;
    return 0;
}

