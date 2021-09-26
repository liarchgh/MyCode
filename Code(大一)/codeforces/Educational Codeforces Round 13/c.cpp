//注意数据溢出问题
#include<cstdio>

long long int gcd(long long int a,long long int b);
int main()
{
    long long int n,a,b,p,q;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&p,&q);
    long long int a1=n/a,b1=n/b,g=a/gcd(a,b)*b;
    if(p>=q) b1-=n/g;
    else if(p<q) a1-=n/g;
    printf("%I64d\n",a1*p+b1*q);
    return 0;
}

long long int gcd(long long int a,long long int b)
{
    if(!a) return b;
    return gcd(b%a,a);
}
