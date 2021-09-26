#include<cstdio>
unsigned long long int num[60]={0,1,2,3,4};
void suan()
{
    for(int i=5;i<56;++i)
        num[i]=num[i-1]+num[i-3];
}
int main()
{
    int n;
    suan();
    while(scanf("%d",&n),n)
    {
        printf("%u\n",num[n]);
    }
    return 0;
}
