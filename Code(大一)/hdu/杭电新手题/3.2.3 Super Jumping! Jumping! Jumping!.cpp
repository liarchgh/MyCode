#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[1005],dp[1005];
const int inf = 999999999;

int main()
{
    int n,i,t,m,j,ans;
    while(~scanf("%d",&n),n)
    {
        memset(dp,0,sizeof(dp));
        for(i = 1;i<=n;i++)
        scanf("%d",&a[i]);
        for(i = 1;i<=n;i++)
        {
            ans = -inf;
            for(j = 0;j<i;j++)
            {
                if(a[i]>a[j])
                ans = max(ans,dp[j]);
            }
            dp[i] = ans+a[i];
        }
        ans = -inf;
        for(i = 0;i<=n;i++)
        {
            if(dp[i]>ans)
            ans = dp[i];
        }
        printf("%d\n",ans);
    }

    return 0;
}

/*#include<cstdio>
#include<algorithm>
using namespace std;
int d[1005],s[1005],N,ans;
void dp();
int main()
{
    while(scanf("%d",&N),N)
    {
        ans=0;
        for(int i=0;i<N;++i)
            {scanf("%d",&s[i]);}
        d[N-1] = s[N-1];
        dp();
        printf("%d\n",ans);
    }
    return 0;
}

void dp()
{
    for(int i=N-2;i>=0;--i)
        {
            d[i]=s[i];
            for(int j=i;j<N;++j)
            {
                if(s[i]<s[j] && (s[j-1]>=s[j] || i==j-1))
                    d[i]=max(d[j]+s[i],d[i]);
            }
            ans=max(ans,d[i]);
        }
}
*/
