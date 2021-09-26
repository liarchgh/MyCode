#include<stdio.h>
double *fun(int a,int b)
{
    double he=0;
    int i;
    if(b) i=2;
    else i=1;//printf("%d\n%d\n",he,i);
    while(i<=a)
    {
        he+=1/(double)(i++);//printf("%d\n%d\n",he,i);
        ++i;
    }
    return &he;
}
void main()
{
    int n,t;
    double ans;
    scanf("%d",&n);
    if(n%2) t=0;
    else t=1;
    ans=*fun(n,t);
    printf("it is %f\n",ans);
}
