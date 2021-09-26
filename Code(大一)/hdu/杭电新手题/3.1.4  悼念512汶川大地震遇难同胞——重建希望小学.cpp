#include<cstdio>
int shu[35]={0,1,3};
void suan()
{
    for(int i=3;i<=30;++i)
        shu[i]=shu[i-1]+2*shu[i-2];//printf("%d\n",shu[i]);}
}
int main()
{
    suan();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",shu[n]);
    }
    return 0;
}
