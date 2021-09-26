//DP 没有看出来。。。。。 而且dp数组和ans用int会爆掉
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string ss[100005][2];
const long long inf=0x7fffffffffffffff;
long long cost[100005],dp[100005][2]= {0};
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%I64d",&cost[i]);
        //cout<<cost[i]<<endl;
        dp[i][0]=dp[i][1]=inf;
        //cout<<dp[i][0]<<endl<<dp[i][1]<<endl;
    }
    for(int i=0; i<n; ++i) {
        cin>>ss[i][0];
        for(int j=ss[i][0].size()-1; j>=0; --j) {
            ss[i][1]+=ss[i][0][j];
        }
        //cout<<ss[i][1]<<endl;
    }
    dp[0][1]=cost[0];dp[0][0]=0;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < 2; ++j) {
            for(int jj=0; jj < 2; ++jj) {
                if(ss[i][j] >= ss[i-1][jj]) {
                    dp[i][j]=min(dp[i][j],dp[i-1][jj]);
                    //printf("%d %d %d %d\n",i,j,jj,dp[i][j]);
                }
            }
            if(dp[i][j]!=inf && j==1) dp[i][j]+=cost[i];
        }
    }
    long long int ans=min(dp[n-1][0],dp[n-1][1]);
    if(ans==inf) {
        printf("-1\n");
    } else printf("%I64d\n",ans);
    return 0;
}
