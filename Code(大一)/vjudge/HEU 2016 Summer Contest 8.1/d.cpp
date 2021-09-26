////*将快速幂的思想应用于快速求可能爆掉longlong的乘积
#include<cstdio>

long long qiuji(long long q,long long p);//求(q-1)(q-2)/2modp
int main()
{
    long long q,p;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&q,&p);
        printf("%lld\n",qiuji(q,p));
    }
    return 0;
}

long long qiuji(long long q,long long p)//求(q-1)(q-2)/2modp
{
    long long q1=q-1,q2=q-2;
    if((q-1)&1)
    {
        q2>>=1;
    }
    else
    {
        q1>>=1;
    }
    q1%=p;q2%=p;
    long long ans=0;
    if(q1>q2)
    {
        long long t=q1;q1=q2;q2=t;
    }//printf("%lld %lld\n",q1,q2);
    while(q1)
    {
        if(q1&1)
        {
            ans=(ans+q2)%p;
        }
        q2=q2*2%p;
        q1>>=1;
    //printf("%lld\n",ans);
    }
    return ans;
}
/*/


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define ll __int64
using namespace std;
ll p_mod(ll q1,ll q2,ll p)
{
    ll sum=0;
    while(q2)
    {
        if(q2&1)
        {
            sum+=q1;
            sum%=p;
        }
        q1<<=1;
        q1%=p;
        q2>>=1;
    }
    return sum;
}
int main()
{
    int t,n,m;
    ll p,q;
    ll q1,q2,pp;
    int i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&q,&p);
        q1=q-1;q2=q-2;
        if(q1&1)
            q2>>=1;
        else
            q1>>=1;
        printf("%lld\n",p_mod(q1,q2,p));
    }
    return 0;
}

*/
