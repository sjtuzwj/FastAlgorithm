//二进制思想
#include<cstring>
#include<iostream>
using namespace std;
const int M = 1e9+7;
struct Matrix
{
    long long a[2][2];
    Matrix() {//构造函数
        memset(a, 0, sizeof(a));
    }
    Matrix operator * (const Matrix y) {//*运算符重载
        Matrix ans;
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                for(int k = 0; k <= 1; k++)
                    ans.a[i][j] += a[i][k]*y.a[k][j];
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                ans.a[i][j] %= M;
        return ans;
    }
    void operator = (const Matrix b) {//=运算符重载
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                a[i][j] = b.a[i][j];
    }
};
//矩阵[Fn+1 Fn Fn Fn-1]=[1 1 1 0]^n
int solve(long long x) {//101001001等价于1+1000+1000000+100000000等价于A^1+A^1000+A^1000000+A^100000000
    Matrix ans, trs;
    ans.a[0][0] = ans.a[1][1] =1;//斐波那契数列
    trs.a[0][0] = trs.a[1][0] = trs.a[0][1] = 1;//矩阵幂
    while(x)
    {
        if(x&1)//每一个bit都与1进行与运算，仅有1&1=1，即奇数为1，偶数为0
        ans = ans*trs;//trs=自右向左的位数次幂
        trs = trs*trs;
        x >>= 1;//右移运算符，二进制每一个bit向右移动，最左的bit变为0(扫描）
    }
    return ans.a[0][0];
}
int main() {
    long long n;
    cin>>n;
    cout << solve(n) << endl;//左上角return Fn+1
    return 0;
}
