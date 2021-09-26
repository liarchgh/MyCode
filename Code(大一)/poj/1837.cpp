//照着背包九讲找到是 泛化物品背包 试着用一维数组做 发现不行 得二维的
//然而POJ不能上 貌似是因为G20峰会
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 804;
int a[25][mx+1];

int main() {
#ifndef ONLINE_JUDGE
   freopen("C:\\in.txt", "r", stdin);
   freopen("C:\\out.txt", "w", stdout);
#endif
   int c, g, val = 401, pos[25];
   scanf("%d%d", &c, &g);
   for(int i = 0; i < c; ++i) {
      scanf("%d", &pos[i]);
   }
   int b, ans = 0;
   memset(a, 0, sizeof(a));
   for(int i = 1; i <= g; ++i) {
      scanf("%d", &b);
      for(int j = 0; j < c; ++j) {
         int d = b * pos[j];
         int p = d/abs(d);
         for(int k = mx/2 + mx/2 * p; k >= 0 && k <= mx; k -= p) {
            //printf("\t%d\n", k);
            if(a[i-1][k]) {
               a[i][k] = 1;
               a[i][k+d] = 1;
               if(k + d == val) ++ans;
            }
         }
      }
      for(int j = 0; j < c; ++j) {
         int d = b * pos[j];
         a[i][val+d] = 1;
      }
   }
   printf("%d\n", ans);
   return 0;
}
