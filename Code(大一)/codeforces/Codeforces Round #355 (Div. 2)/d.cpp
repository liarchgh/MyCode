#include<cstdio>
int d[905][905][2]= {0};
    int n,m,p,be=0;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            int t;
            scanf("%d",&t);
            if(!p) p=t;
            d[t][d[t][0][0]+1][0]=i;
            d[t][d[t][0][0]+1][1]=j;
            ++d[t][0][0];
        }
    __int64 sum=0;
    if(be>p) sum=zhao(1)+;
    else if(be<p)
    printf("%d\n",sum);
    return 0;
}
