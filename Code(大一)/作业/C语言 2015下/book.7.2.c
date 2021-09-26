#include<stdio.h>
int fun(int a)
{//printf("%d\n",a);
    int j,n,b,m,c=0,i=a;
    n=1;
    while(i>9)
    {//printf("%d\n",n);
        i/=10;
        ++n;//printf("%d\n",n);printf("%d\n",i);
    }//printf("%d\n",n);
    m=n;
    if(n==1) return a;
    else
    {
        for(i=0; i<m; ++i)
        {
            b=a%10;//printf("%d\n",b);
            for(j=0; j<n-1; ++j)
                b*=10;
            c+=b;//printf("%d\n",b);
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
