#include<iostream>
#include<cmath>
using namespace std;
void screen(int);
int main()
{
    int n;
    cin>>n;
    screen(n);
    return 0;
}
void screen(int n)
{
    bool *check=new bool[n+1];
    int i=3;
    int m=sqrt(n);
    cout<<2;
    while(i<=m)
    {
        if(!check[i])
        {
        cout<<' '<<i;
        for(int j=i*i;j<=n;j+=i)
        {
            check[j]=true;
        }
        }
        i+=2;
    }
    while(i<=n)
    {
        if(!check[i])
        cout<<' '<<i;
        i+=2;
    }
    delete[]check;
}
