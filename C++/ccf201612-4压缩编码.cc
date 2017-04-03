//比赛的时侯没有过 这几天看了下 使用石子合并问题思路来做的 当时傻掉了 现在写出来后稍微调试一下就100了 一次过 不太难 就是思路 2017.3.17
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 1000 + 5;
int time[mx], num, dp[mx][mx], sum[mx][mx];

int out(int l, int r, int now);

int main(){
    freopen("in.ls", "r", stdin);
    freopen("out.ls", "w", stdout);
    scanf("%d", &num);
    memset(dp, 0x7f, sizeof(dp));
    for(int i = 0; i < num; ++i){
        scanf("%d", &dp[i][i]);
        sum[i][i] = dp[i][i];
    }

    for(int jia = 1; jia < num; ++jia){
        for(int now = 0; now + jia < num; ++now){
            sum[now][now + jia] = sum[now][now + jia - 1] + dp[now + jia][now + jia];
        }
    }

    for(int jia = 1; jia < num; ++jia){
        for(int now = 0; now + jia < num; ++now){
            for(int i = now + 1; i <= now + jia; ++i){
                dp[now][now + jia] = min((dp[now][i - 1] + dp[i][now + jia]) + sum[now][now + jia], dp[now][now + jia]);
            }
        }
    }

    printf("%d\n", out(0, num - 1, 0));
    return 0;
}

int out(int l, int r, int now){
    if(l == r){
        return now * dp[l][r];
    }
    int mid;
    for(mid = l + 1; mid <= r; ++mid){
        if(dp[l][mid - 1] + dp[mid][r] + sum[l][r] == dp[l][r]){
            break;
        }
    }
    return out(l, mid - 1, now + 1) + out(mid, r, now + 1);
}


