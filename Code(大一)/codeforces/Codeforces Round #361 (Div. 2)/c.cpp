#include<cstdio>

__int64 cifang(__int64 x)
{
    return x*x*x;
}
int pan(__int64 x,__int64 m)
{
    __int64 i,sum=0;
    for(i=2;i<=1e6;++i)
        sum+=x/cifang(i);
    //printf("1\n");
    if(sum<m) return 0;
    else if(sum>m) return 1;
    return -1;
}
int main()
{
    __int64 n,m,l=1,r=1e18;
    scanf("%I64d",&m);
    //printf("%d\n",m);
    while(l<=r)
    {
        __int64 mid=(l+r)/2;
        //printf("%I64d %I64d\n",l,r);
        if(!pan(mid,m))
            l=mid+1;
            else r=mid-1;
    }
    if(pan(l,m)==-1)
    printf("%I64d\n",l);
    else printf("-1\n");
    return 0;
}
//936ms
