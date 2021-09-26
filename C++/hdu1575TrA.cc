//居然声明变量声明错了 简直了 真的是生疏了 一道简单的矩阵快速幂的题目 毫无弯处
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 9973, mx = 15;
int n, k;

struct mat
{
    int num[mx][mx];
    mat()
    {
        memset(num, 0, sizeof(num));
    }
    mat operator*(mat x)
    {
        mat ans;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                int & d = ans.num[i][j];
                for(int t = 0; t < n; ++t)
                {
                    d = (d + num[i][t] * x.num[t][j]) % mod;
                }
            }
        }
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
#endif
    int t;
    scanf("%d",  &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        mat eve, be;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                scanf("%d", &eve.num[i][j]);
            }
            be.num[i][i] = 1;
        }
        while(k)
        {
            if(k & 1)
            {
                be = be * eve;
            }
            k >>= 1;
            eve = eve * eve;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ans = (ans + be.num[i][i]) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}
