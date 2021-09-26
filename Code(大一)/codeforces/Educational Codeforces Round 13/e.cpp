#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
double d[1<<19-1][19],p[19][19];
double zhao(int rec,int x);//n为用二进制记录已经走过的选手(倒着来的) x为最后一个选手
int main()
{
    //for(int i=1;i<100;++i) printf("%llf  ",d[i]);
    scanf("%d",&n);
    for(int i=0;i<1<<19-1;++i)
    {
        for(int j=0;j<19;++j)
            d[i][j]=0.0;
    }
    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
        scanf("%lf",&p[i][j]);
    double ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,zhao(1<<(i-1),i));
    printf("%lf\n",ans);
    return 0;
}

double zhao(int rec,int x)
{
    if(rec==((1<<n)-1)) return 1;
    if(d[rec][x]) return d[rec][x];
    double ans=0;
    for(int i=1;i<=n;++i)
    {
        if(rec&1<<(i-1)) continue;
        if(rec&1)
            ans+=p[x][i]*zhao(rec+(1<<(i-1)),i);
        else
            ans=max(ans,p[1][x]*zhao(rec+(1<<(i-1)),i));
    }
    d[rec][x]=ans;
    printf("%lf  ",ans);
    return ans;
}
