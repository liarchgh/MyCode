#include<stdio.h>
void main()
{
    int a,b,x;
    scanf("%d%d",&a,&b);
    x=a*a+b*b;
    if(x>100)
        printf("%d",x/100);
    else printf("%d",x);
}
