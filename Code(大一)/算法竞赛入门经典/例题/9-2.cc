#include<cstdio>
#include<cstring>
#incldue<algorithm>
const int maxn = 200;
int dp[maxn][3],n;
struct node
{
    int h[3],v;
    bool operator < (const node & b) const
    {
        return v<b.v;
    }
}
int dag(int i,int j)
{
    int & ans = dp[i][j];
    if(ans>0) return ans;
    ans = a[i].h[j];
    int x= j == 0 ? a[i].h[1]:a[i].h[0];
    int y= j == 2 ? a[i].h[1]:a[i].h[2];
    for(int i0 = 0;i0 < n;++i0)
        for(int j0 = 0;j0 < n;++j0)
            {
                int x0= j0 == 0 ? a[i0].h[1]:a[i0].h[0];
                int y0= j0 == 2 ? a[i0].h[1]:a[i0].h[2];
                if(x < x0 && y < y0) ans=max(ans,dag(i0,j0));
            } 
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        node a[n];
        for(int i=0;i<n;++i)
        {
            a[i].v=1;
            for(int j=0;j<3;++j)
                {scanf("%d",&a[i].h[j]);a[i]*=a[i].h[j];}
            sort(a[i],a[i]+3);
        }
        sort(a,a+n);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=0;i<n;++i)
            for(int j=0;j<3;++j)
                res = max(res, dp(i,j));
    }
    return 0;
}