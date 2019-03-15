//������˼��
#include<cstring>
#include<iostream>
using namespace std;
const int M = 1e9+7;
struct Matrix
{
    long long a[2][2];
    Matrix() {//���캯��
        memset(a, 0, sizeof(a));
    }
    Matrix operator * (const Matrix y) {//*���������
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
    void operator = (const Matrix b) {//=���������
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                a[i][j] = b.a[i][j];
    }
};
//����[Fn+1 Fn Fn Fn-1]=[1 1 1 0]^n
int solve(long long x) {//101001001�ȼ���1+1000+1000000+100000000�ȼ���A^1+A^1000+A^1000000+A^100000000
    Matrix ans, trs;
    ans.a[0][0] = ans.a[1][1] =1;//쳲���������
    trs.a[0][0] = trs.a[1][0] = trs.a[0][1] = 1;//������
    while(x)
    {
        if(x&1)//ÿһ��bit����1���������㣬����1&1=1��������Ϊ1��ż��Ϊ0
        ans = ans*trs;//trs=���������λ������
        trs = trs*trs;
        x >>= 1;//�����������������ÿһ��bit�����ƶ��������bit��Ϊ0(ɨ�裩
    }
    return ans.a[0][0];
}
int main() {
    long long n;
    cin>>n;
    cout << solve(n) << endl;//���Ͻ�return Fn+1
    return 0;
}
