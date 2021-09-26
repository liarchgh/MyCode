/* #include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 22;
int n,g[mx][mx][2],link[mx],vis[mx],biao[2][mx];

int gengxin(int val) {
   int ans = 0xfffffff;
   for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
         ans = min(ans, biao[0][i] + biao[1][j] - g[i][j][(1<<i)&val]);
      }
   }
   return ans;
}

int find(int x, int val) {
   int b = 0;
   for(int i = 1; i < n; ++i) {
      if(vis[i]) continue;
      if()
         return find(x, val);
   }
   if(link[i] == -1) {
      link[i] = x;
      return 1;
   } else {
      int a = gengxin(val);
      for(int j = 0; j < n; ++j) {
         if(link[j] != -1) {
            biao[0][link[j]] += a;
            biao[1][link[j]] -= a;
         }
      }
   }
   return 0;
}

int chuan(int th, int num, int val) { //th为传进来之前已经有几位了 num为1的个数 val就是压缩后的状态 0 星期六 1 星期一
   if(num == n>>1) {
      //printf("!!!!!!\n");
      val <<= (n-th);
      int ans=0;
      memset(biao, 0, sizeof(biao));
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < n; ++j) {
            biao[0][i] = max(biao[0][i], g[i][j][1 << i & val]);
         }
      }
      for(int i = 0; i < n; ++i) {
         memset(vis, 0, sizeof(vis));
         ans += find(i, val);
      }
      return ans;
   }
   if(n-th < (n>>1)-num) return -1;
   return max(chuan(th+1, num, val<<1), chuan(th+1, num+1, val<<1|1));
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("C:\\in.txt", "r", stdin);
   freopen("C:\\out.txt", "w", stdout);
#endif
//printf("000\n");
   scanf("%d", &n);
   for(int ti = 0; ti < 2; ++ti) {
      for(int i = 0; i < n; ++i) {
         for(int j = 0; j < n; ++j) {
            scanf("%d", &g[i][j][ti]);
            //printf("%d\t",g[i][j][ti]);
         }
         //putchar('\n');
      }
   }
   printf("%d\n", chuan(0, 0, 0));
   return 0;
}
 */

#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <stdio.h>
#include <ctime>
using namespace std;
template <class T>inline bool rd(T &ret) {
   char c;
   int sgn;
   if (c = getchar(), c == EOF) return 0;
   while (c != '-' && (c < '0' || c > '9')) c = getchar();
   sgn = (c == '-') ? -1 : 1;
   ret = (c == '-') ? 0 : (c - '0');
   while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
   ret *= sgn;
   return 1;
}
template <class T>inline void pt(T x) {
   if (x < 0) {
      putchar('-');
      x = -x;
   }
   if (x > 9) pt(x / 10);
   putchar(x % 10 + '0');
}
typedef pair<int, int> pii;
const int inf = 1e9;
const int N = 22;
const int M = N;
int ans;
struct KM {
   int n, w[M][M];
   int lx[M], ly[M], match[M], slack[M];
   bool s[M], t[M];
   inline bool hungary(int x) {
      s[x] = true;
      for (int y = 0; y < n; ++y)         if (!t[y] && lx[x] + ly[y] == w[x][y]) {
            t[y] = true;
            if (match[y] == -1 || hungary(match[y])) {
               match[y] = x;
               return true;
            }
         }        else slack[y] = min(slack[y], lx[x] + ly[y] - w[x][y]);
      return false;
   }  inline int rediculous() {
      int magic;
      magic = 0;
      for (int i = 0; i < n; ++i) {
         lx[i] = *max_element(w[i], w[i] + n);
         magic += lx[i];
      }
      if (magic <= ans) return 0;
      memset(match, -1, n << 2);
      memset(ly, 0, n << 2);
      for (register int i = 0; i < n; ++i) {
         for (;;) {
            memset(s, 0, n);
            memset(t, 0, n);
            memset(slack, 0x7f, n << 2);
            if (hungary(i)) break;
            else {
               int a = inf;
               for (register int j = 0; j < n; ++j) if (!t[j] && slack[j] < a)
                     a = slack[j];
               magic = 0;
               for (register int j = 0; j < n; ++j) {
                  if (s[j]) lx[j] -= a;
                  if (t[j]) ly[j] += a;
                  magic += lx[j] + ly[j];
               }
               if (magic <= ans) {
                  return 0;
               }
            }
         }
      }
      ans = magic;
      return magic;
   }
} S;
int n;
int a[N][N], b[N][N];
int CNT(int x) {
   int siz = 0;
   while (x) {
      siz += x & 1;
      x >>= 1;
   }
   return siz;
}
int main() {
   clock_t lim = clock() + 1.9 * CLOCKS_PER_SEC;
   rd(n);
   S.n = n;
   for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)rd(a[i][j]);
   for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) rd(b[i][j]);
   ans = 0;
   for (int i = 0; i < 1 << n; ++i)    if (CNT(i) == (n >> 1))    {
         for (int j = 0; j < n; j++)            if (i & (1 << j))               memcpy(S.w[j], a[j], n << 2);
            else              memcpy(S.w[j], b[j], n << 2);
         ans = max(ans, S.rediculous());
         if (clock() >= lim)break;
      }
   pt(ans);
   return 0;
}


