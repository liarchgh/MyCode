#include<cstdio>
#include<cstring>

long long n,k,l,ans=0,d[105][2];
long long shu(int n,int p);//n表示剩余可用的重量 p表示之前有没有走过重量为d的路
const long long mod=1000000007;
int main()
{
    memset(d,-1,sizeof(d));
    scanf("%lld%lld%lld",&n,&k,&l);
    shu(n,0);
    //for(int i=0;i<=100;++i) printf("%lld %lld\n",d[i][0],d[i][1]);
    printf("%lld",ans);
    return 0;
}
long long shu(int n,int p)//n表示剩余可用的重量 p表示之前有没有走过重量为d的路
{
    //printf("%d %d\n",n,p);
    if(d[n][p]!=-1)
    {
        ans=(ans+d[n][p])%mod;
        return d[n][p];
    }
    if(n==0)
    {ans+=p;
    ans%=mod;
    d[0][p]=p;
    return p;}
    long long sum=0;
    for(int i=1;i<=k;++i)
    {
        if(i>n) break;
        if(p || i>=l) sum+=shu(n-i,1);
        else sum+=shu(n-i,0);
        sum%=mod;
    }
    d[n][p]=sum;
    return sum;
}
