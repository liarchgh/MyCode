#include<stdio.h>
void fun(int a[])
{
    int j,i,t,n;//for(i=0;i<10;++i)
    //printf("%d\n",a[i]);
    for(i=0;i<9;++i)
    {t=a[i];//printf("%d\n",t);
    for(j=i;j<9;++j)
    if(t>a[j+1])
        {t=a[j+1];n=j+1;//printf("%d\n",t);}
    a[n]=a[i];a[i]=t;
    }
}
void main()
{
    int a[10],i;
    for(i=0;i<10;++i)
    scanf("%d",&a[i]);
    fun(a);
    for(i=0;i<10;++i)
    printf("%d\n",a[i]);
}
//11 21 1 321 20 51 23 42 57 231
