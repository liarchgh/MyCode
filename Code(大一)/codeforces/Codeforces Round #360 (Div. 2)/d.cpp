#include<cstdio>

long long int a,b,n,k;
long long int qiu(long long int x,long long int y);
int main()
{
    scanf("%I64d%I64d%I64d",&n,&k,&a);
    for(int i=1; i<n; ++i)
    {
        scanf("%I64d",&b);
            a=qiu(a,b);
            a=a%k;
    }
    //printf("%d    ",a);
    if(a%k) printf("No\n");
    else printf("Yes\n");
    return 0;
}

long long int qiu(long long int x,long long int y)
{
    long long int a=x,b=y,t;
    while(a)
    {
        t=a;
        a=b%a;
        b=t;
    }
    return x/b*y;
}
