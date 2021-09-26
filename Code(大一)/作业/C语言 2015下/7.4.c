#include<stdio.h>
int fun(int a[],int n)
{
    int sum=0,i,ge;
    for(i=0; i<n; ++i)
        sum+=a[i];
    sum/=n;
    for(i=0; i<n; ++i)
        if(a[i]>sum) ++ge;
}
void main()
{
    int dayu,n,i;
    printf("How many are the integer?\n");
    scanf("%d",&n);
    int a[n];
    printf("What are they?\n");
    for(i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
    }
    dayu=fun(a,n);
    printf("has%d\n",dayu);
}
