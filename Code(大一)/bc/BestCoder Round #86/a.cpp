#include<cstdio>

int main()
{
    int n,m,t,v;
    long long sum,q;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&v);
        sum+=v;
        }
        for(int i=0;i<m;++i)
        {
            scanf("%lld",&q);
            if(q>sum) printf("1");
            else printf("0");
        }
            putchar('\n');
    }
    return 0;
}
