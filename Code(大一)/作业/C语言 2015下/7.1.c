#include<stdio.h>
int maxgongyue(int a,int b)
{
    int i;
    for(i=a/2;;--i)
        if(b%i==0&&a%i==0) return i;
}
void main()
{
    int m,n,a,b;
    scanf("%d%d",&a,&b);
    n=maxgongyue(a,b);
    m=a*b/n;//a*b等于a、b的最大公约数与最小公倍数的乘积
    printf("最小公倍数是%d,最大公约数是%d。",m,n);
}
