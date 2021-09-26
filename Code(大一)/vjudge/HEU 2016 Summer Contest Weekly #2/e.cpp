#include<cstdio>

long long k,a,b;
int main()
{
    long long l,r;
    scanf("%lld%lld%lld",&k,&a,&b);
    l=a/k*k;if(l<a) l+=k;
    r=b/k*k;if(r>b) r-=k;
    long long ans;
    if(l>r) ans=0;
    else{
        ans=(r-l)/k+1;
    }
    printf("%lld\n",ans);
    return 0;
}
