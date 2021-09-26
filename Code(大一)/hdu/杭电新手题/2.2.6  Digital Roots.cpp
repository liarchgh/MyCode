#include<cstdio>
int js(int a)
{
    int t=0;
    while(a>=10)
    {
        t+=a%10;
        a/=10;
    }
    t+=a;
    return t>=10?js(t):t;
}
int main()
{
    char c;
    int sum;
    while(1)
    {
        sum=0;
        while(c=getchar()!='\n')
        {
            sum += c - '0';
        }
        if(!sum) return 0;
        printf("%d\n",js(sum));
    }
}
