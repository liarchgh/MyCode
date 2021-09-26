#include<stdio.h>
int fun(int a[],int n)
{
    int s,m=0;
    for(s=0;s<n;++s)
        if(0==a[s]%2&&a[s]>m)
            m=a[s];
    return m;
}
void main()
{
    int i,a;
    printf("please write how many:");
    scanf("%d",&a);
    int b[a];
    printf("then you can write the numbers:\n");
    for(i=0;i<a;++i)
        scanf("%d",&b[i]);
    printf("%d",fun(b,a));
}
