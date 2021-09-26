//不太明白第17~24行当中的矩阵的由来 下边算组合数的时候直接就用上了 很神奇
#include<cstdio>
#include<cstring>

const long long mod=1000000007;
char c;
int a[28],d[1111][1111];
long long jiecheng(long long a,long long b,long long x);//返回a~b的阶乘对mod取模
int main()
{
    int t;
    long long num;
    scanf("%d",&t);
    getchar();
    memset(d,0,sizeof(d));
    for (int i = 0; i <= 1000; i++) d[i][0] = 1;
    for(int i=1; i<=1000; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            d[i][j]=(d[i-1][j]+d[i-1][j-1])%mod;
            //if(i<=20)printf("%d %d %d\n",i,j,d[i][j]);
        }
    }
    while(t--)
    {
        memset(a,0,sizeof(a));
        while((c=getchar())!='\n')
        {
            ++a[c-'a'];
        }
        long long sum=0;
        int j=0;
        for(int i=0; i<='z'-'a'; ++i)
        {
            sum+=a[i]/2;
            if(a[i]&1)
            {
                ++j;

            }
            a[i]/=2;
        }
        if(j>1)
        {
            printf("0\n");
            continue;
        }
        num=1;
        for(int i=0; i<='z'-'a'; ++i)
        {
            //printf("%I64d\n",num);
            num=num*d[sum][a[i]]%mod;
            sum-=a[i];
        }
        printf("%I64d\n",num);
    }
    return 0;
}
//
//long long jiecheng(long long a,long long b,long long x)//返回a~b的阶乘对mod取模
//{
//    a%=mod;
//    for(long long i=a+1;i<=b;++i)
//    {
//
//        while(!(a%x) && x>1) a/=x--;
//        a=a*i;
//        if(x==1) a%=mod;//printf("%lld\n",a);
//    }
//    return a;
//}
