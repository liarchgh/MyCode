#include<cstdio>

const long long int mod=1000000007;//注意 用10e7得不出正确结果
long long int pow(long long int n,long long int x);
int main()
{
    long long int n,a,b,x,ans;
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&x);
    if(a==1) ans=(x+n%mod*b)%mod;
    else
    {
        ans=((pow(a,n)-1)%mod)*(pow(a-1,mod-2)%mod)%mod;
        ans=(ans*b%mod+pow(a,n)*x%mod)%mod;
        //ans=(ans+mod)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}

long long int pow(long long int n,long long int x)
{
    //printf("%I64d %I64d   ",n,x);
    long long ans=1;
    while(x)
    {
        if(x&1) ans=ans*n%mod;
        n=n*n%mod;
        x>>=1;
        //printf("%d  ",n);//if(!n) break;
    }
    //printf("%I64d\n",ans);
    return ans;
}
