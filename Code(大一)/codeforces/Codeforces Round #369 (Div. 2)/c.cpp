//一道简单的DP题 然而当时却没写出来 有点复杂
#include <cstdio>
#include <algorithm>

using namespace std;

const int mx=105;
const long long int inf=0xfffffffffffffff;
int c[105],p[105][105]= {0};
long long dp[mx][mx][mx]= {0}; //dp[x][y][z] 依次为 前x个 y种group 最后一颗颜色为z 的最少花费
//dp[x][y][z]=min(dp[x][y][z],dp[x-1][y-1][0-m],dp[x-1][y][z]);
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<mx; ++i) {
        for(int j=0; j<mx; ++j) {
            for(int k=0; k<mx; ++k) {
                dp[i][j][k]=inf;
            }
        }
    }
    for(int i=0; i<n; ++i) {
        scanf("%d",&c[i]);
    }
    for(int i=0; i<n; ++i) {
            for(int j=1; j<=m; ++j) {
                scanf("%d",&p[i][j]);
            }
    }
    for(int i=0; i<n; ++i) {
        //printf("%d\n",i);
        if(c[i]) {
            if(i==0) {
                dp[0][1][c[i]]=0;
                continue;
            }
            for(int j=1; j<=i+1; ++j) {
                dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j][c[i]]);
                for(int k=0; k<=m; ++k) {
                    if(k!=c[i])
                        dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j-1][k]);
                    else dp[i][j][c[i]]=min(dp[i][j][c[i]],dp[i-1][j][k]);
                }
            }
        } else {
            if(i==0) {
                for(int ii=1; ii<=m; ++ii) {
                    dp[0][1][ii]=p[0][ii];
                }
            } else {
                for(int co=1; co<=m; ++co) {
                    for(int j=1; j<=i+1; ++j) {
                        for(int k=0; k<=m; ++k) {
                            if(k!=co)
                                dp[i][j][co]=min(dp[i][j][co],dp[i-1][j-1][k]+p[i][co]);
                            else {
                                dp[i][j][co]=min(dp[i][j][co],dp[i-1][j][k]+p[i][co]);
                            }
                        }
                    }
                }
            }
        }
    }
    long long ans=inf;
//    for(int i=0; i<n; ++i) {
//        for(int ii=0; ii<=k; ++ii)
//            for(int j=0; j<=m; ++j) {
//                printf("%d %d %d %I64d\n",i,ii,j,dp[i][ii][j]);
//            }
//    }
    for(int i=0; i<=m; ++i) {
        ans=min(ans,dp[n-1][k][i]);
    }
    if(ans==inf) {
        printf("-1\n");
        return 0;
    }
    printf("%I64d\n",ans);
    return 0;
}
//3 2 2 2 0 0 1 3 2 4 3 5
//3 2 2 2 1 2 1 3 2 4 3 5
//3 2 2 0 0 0 1 2 3 4 5 6
