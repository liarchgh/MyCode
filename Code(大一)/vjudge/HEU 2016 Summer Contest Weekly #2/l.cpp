#include<cstdio>

int main()
{
    long long int t,s,x;
    scanf("%lld%lld%lld",&t,&s,&x);
    if(x==t+1 || x<t)
    {
        printf("NO\n");return 0;
    }
    x-=(x-t)/s*s;
    if(x==t || x==t+1)
    {
        printf("YES\n");return 0;
    }printf("NO\n");
    return 0;
}
