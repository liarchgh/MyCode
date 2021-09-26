//一开始的思路完全错了 直接就用list去模拟了 稍稍优化一下 WA 上网找了一下代码 原来是用最简单的01背包的方法 惭愧
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const long long int inf = 0xfffffffffffffff;

int main() {
#ifndef ONLINE_JUDGE
   freopen("C:\\in.txt", "r", stdin);
   freopen("C:\\out.txt", "w", stdout);
#endif
   int n, t[2005], c[2005];
   long long dp[5005];
   scanf("%d", &n);
   for(int i = 0; i < n; ++i) {
      scanf("%d%d", &t[i], &c[i]);
      ++t[i];
      //printf("\t%d\t%d\n", t[i], c[i]);
      dp[i] = inf;
   }
   dp[n] = inf;
   //long long int cost = 0;//int sd = 0;
   dp[0] = 0;
   for(int i = 0; i < n; ++i) {
      for(int j = n-1; j >= 0; --j) {
         if(dp[j] != inf || !j) {
            if(j + t[i] < n) {
               dp[j+t[i]] = min(dp[j+t[i]], dp[j] + c[i]);
            } else {
               dp[n] = min(dp[n], dp[j] + c[i]);
            }
            //printf("\t%d\t%d\t%lld\n", j, i, dp[j+t[i]]);
         }
      }
   }
   printf("%lld\n", dp[n]);
   return 0;
}
