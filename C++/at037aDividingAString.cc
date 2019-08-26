// https://atcoder.jp/contests/agc037/tasks/agc037_a
// Given is a string S consisting of lowercase English letters. Find the maximum positive integer K
// that satisfies the following condition:
//     There exists a partition of S
// into K non-empty strings S=S1S2...SK such that Si≠Si+1 (1≤i≤K−1
//     ).
// Here S1S2...SK
// represents the concatenation of S1,S2,...,SK in this order.
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#define LS_DEBUG
using namespace std;

const int maxN = 2e5+5;
char ins[maxN];
int dp[maxN][2];
int len;

int getMaxSizeAt(int x, int y){
    if((x < 0 && x >= maxN)
    || (y < 0 && y >= 2)) {
        return 0;
    }
    return dp[x][y];
}

int main(){
#ifdef LS_DEBUG
    freopen("in", "r", stdin);
#endif
    scanf("%s", ins);
    len = strlen(ins);

    for(int idx = 0; idx < len; ++idx){
        dp[idx][0] = getMaxSizeAt(idx-1, 1)+1;
        if(idx >= 1 && ins[idx] != ins[idx-1]){
            dp[idx][0] = max(getMaxSizeAt(idx,0), getMaxSizeAt(idx-1,0)+1);
        }
        if(idx<1){
            dp[idx][1] = 0;
        }
        else{
            dp[idx][1] = getMaxSizeAt(idx-2,0)+1;
            if(idx>=3 && (ins[idx] != ins[idx-2]
            || ins[idx-1] != ins[idx-3])){
                dp[idx][1] = max(getMaxSizeAt(idx,1), getMaxSizeAt(idx-2,1)+1);
            }
        }
    }

#ifdef LS_DEBUG
    for(int idx = 0; idx < len; ++idx){
        printf("%d %d\n", dp[idx][0], dp[idx][1]);
    }
#endif

    printf("%d\n", max(dp[len-1][0], dp[len-1][1]));
    return 0;
}
