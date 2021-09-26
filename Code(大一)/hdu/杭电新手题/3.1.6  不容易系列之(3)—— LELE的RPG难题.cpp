#include<cstdio>
__int64 rgb[55]={0,3,6};
void suan()
{
    __int64 a=12;
    for(int i=3;i<=51;++i)
    {
        rgb[i]=a-rgb[i-1];
        a*=2;
        //printf("%I64d %I64d\n",rgb[i],a);
    }
}
int main()
{
    suan();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",rgb[n]);
    }
    return 0;
}
