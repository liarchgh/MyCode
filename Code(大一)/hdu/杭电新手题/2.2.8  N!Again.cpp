#include<cstdio>
int a[2015]={1,1};
void suan()
{
    for(int i=2;i<=45;++i)
        a[i]=(a[i-1]*i)%2009;//printf("%d\n",a[i]);}
}
int main()
{
    int n;
    suan();
    while(scanf("%d",&n)!=EOF)
    {
        if(n>=2009) printf("0\n");
        else printf("%d\n",a[n]);
    }
    return 0;
}
