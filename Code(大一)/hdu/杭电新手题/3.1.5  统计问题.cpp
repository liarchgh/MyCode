#include<cstdio>
int bu[25]={0,3},fu[25]={0,2};
void suan()
{
    for(int i=2;i<=20;++i)
    {
        bu[i]+=bu[i-1]+fu[i-1]*2;
        fu[i]=fu[i-1]+bu[i-1];
        //printf("%d\n",bu[i]);
    }
}
int main()
{
    suan();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",bu[n]);
    }
    return 0;
}
