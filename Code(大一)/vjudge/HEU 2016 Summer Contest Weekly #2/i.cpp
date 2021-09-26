#include<cstdio>

int main()
{   long long a,d,k,b,t,ta;
    scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
    if(a>=b)
    {   printf("%lld\n",d*b);
        return 0; }
    ta=d/k*t+d*a;
    long long tl,tr,jian=0;
    for(tr=d/k,tl=0; tl!=tr;)
    {   long long mid=(tl+tr)>>1;
        if(mid*t+((mid-1)*k+d%k)*a>((mid-1)*k+d%k)*b)
        {   tr=mid; }
        else tl=mid+1; }
    ta=(d/k-1)*t+d/k*k*a+(d%k*a+t>d%k*b?d%k*b:d%k*a+t);
    long long ans=ta>tb?tb:ta;
    printf("%lld\n",ans);
    return 0; }

//10 2 1 2 3
//1-10 22
//1-2 18
//1-8 21
//1-4 19
