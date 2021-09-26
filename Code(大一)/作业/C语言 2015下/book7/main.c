#include<stdio.h>
int fun(int a)
{
    int i=a,j,n,b,m,c=0;
    n=1;
    while(i>9)
    {
        i/=10;
        ++n;
    }printf("%d\n",n);
    m=n;
    if(n=1) return a;
    else
    {
        for(i=0; i<m; ++i)
        {
            b=a%10;
            for(j=0; j<n+1; ++j)
                b*=10;
            c+=b;
            a/=10;
            --n;
        }
        return c;
    }
}
void main()
{
    int a;
    while(scanf("%d",&a))
    {
    a=fun(a);
    printf("%d\n",a);
}
}
