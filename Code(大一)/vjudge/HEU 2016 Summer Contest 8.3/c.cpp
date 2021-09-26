//很神奇的一种姿势 用sum数组记录了从第一个节点到现在结点所有的路径数目和 通过相减得到某一段区间到最后一节点的路径数目
//dp为到达此点的路径数目和
#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int> >ev;
const long long mod=1000000007;
long long sum[200005]={1},ans=0,dp[200005]={0};
int main()
{
    int n,m,x1,x2;
    scanf("%d%d",&n,&m);
    if(m==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&x2,&x1);
        ev.push_back({x1,x2});
    }
    ev.push_back({0,0});
    sort(ev.begin(),ev.end());
    for(int i=1;i<m+1;++i)
    {
        int a=lower_bound(ev.begin(),ev.end(),make_pair(ev[i].second,-1))-ev.begin()-1,
            b=lower_bound(ev.begin(),ev.end(),make_pair(ev[i].first,-1))-ev.begin()-1;
        dp[i]=(sum[b]-sum[a]+mod)%mod;
        sum[i]=(sum[i-1]+dp[i])%mod;
        if(ev[i].first==n) ans=(ans+dp[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
