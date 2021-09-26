#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[26][26],an1,d[26][26],ans,n;
int zhao(int q1,int sum);
int main()
{
    int m;
    while(scanf("%d%d",&n,&m),n|m)
    {
        int q1,w1;
        an1=ans=-1;
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&q1,&w1);
            a[q1][w1]=a[w1][q1]=1;
        }
        printf("%d ",q1);
        zhao(q1,0);
        printf("%d\n",an1);
        ans=0;
        memset(d,0,sizeof(d));
        zhao(an1,0);
        printf("%d\n",an1);
        printf("%d\n",ans);
    }
    return 0;
}

int zhao(int q1,int sum)
{
    printf("sum=%d\n",sum);
    for(int i=0; i<n; ++i)
    {
        if(sum>ans)
        {
            ans=sum;
            an1=q1;
        }
        int x1=min(q1,i),x2;
        x2=q1+i-x1;
        if(a[q1][i] && !d[x1][x2])
        {
            d[x1][x2]=1;
            printf("%d %d  ",q1,i);
            zhao(i,sum+1);
        }
    }
    return sum;
}
