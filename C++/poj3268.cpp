//过了 但是中间卡了一段时间 原来是标记改变的时机不对 明明很简单啊！！！
#include <queue>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

const int mx = 1004;
int road[mx][mx], go[mx], ret[mx];

int main() {
#ifndef ONLINE_JUDGE
   freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
   freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
   int n, m, l;
   scanf("%d%d%d", &n, &m, &l);
   memset(road, -1, sizeof(road));
   for (int i = 0, a, b; i < m; ++i) {
      scanf("%d%d", &a, &b);
      scanf("%d", &road[a - 1][b - 1]);
      // printf("%d %d %d\n", a - 1, b - 1, road[a - 1][b - 1]);      
   }
   int mar[n], next;
   memset(mar, 0, sizeof(mar));
   memset(go, -1, sizeof(go));
   go[l - 1] = 0;
   next = l - 1;
   while (1) {
      int x = next;
      mar[x] = 1;
      for (int i = 0; i < n; ++i) {
         if (road[i][x] >= 0 && !mar[i] && (road[i][x] + go[x] < go[i] || go[i] < 0)) {
            go[i] = road[i][x] + go[x];
         }
         if (!mar[i] && go[i] >= 0 && (next == x || go[next] > go[i])) next = i;
      }
      if (x == next) break;
   }
   memset(mar, 0, sizeof(mar));
   mar[l - 1] = 1;
   memset(ret, -1, sizeof(ret));
   ret[l - 1] = 0;
   next = l - 1;
   while (1) {
      int x = next;
      mar[x] = 1;
      for (int i = 0; i < n; ++i) {
         if (road[x][i] >= 0 && !mar[i] && (road[x][i] + ret[x] < ret[i] || ret[i] < 0)) {
            ret[i] = road[x][i] + ret[x];
         }
         if (!mar[i] && ret[i] >= 0 && (next == x || ret[next] > ret[i])) {
            next = i;
         }
      }
      if(next == x) break;
   }
   int ans = 0;
   for (int i = 0; i < n; ++i) {
      ans = max(ans, go[i] + ret[i]);
      // printf("%d %d\n", go[i], ret[i]);
   }
   printf("%d\n", ans);
   return 0;
}