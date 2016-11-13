//开始没有思路 在纠结选择什么算法 prime想用但是好像不能算带负边权的 上网查了一下 选择了B-F算法 说白了就是暴力 还好数据量不大
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

const int mx = 504, inf = 0xfffffff;
struct edge {
   int l, r, len;
   edge(int a, int b, int c) {l = a; r = b; len = c;}
};
vector<edge>path, wormhole;

int main() {
#ifndef ONLINE_JUDGE
   freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
   freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
   int f, n, m, w, a, b, l;
   scanf("%d", &f);
   while (f--) {
      path.clear();
      scanf("%d%d%d", &n, &m, &w);
      for (int i = 0; i < m; ++i) {
         scanf("%d%d%d", &a, &b, &l);
         path.push_back(edge(a - 1, b - 1, l));
      }
      for (int i = 0; i < w; ++i) {
         scanf("%d%d%d", &a, &b, &l);
         path.push_back(edge(a - 1, b - 1, -l));
      }
      int tim[n], p;
      for (int st = 0; st < n; ++st) {
         for (int i = 0; i < n; ++i) tim[i] = inf;
         tim[st] = 0;
         p = 1;
         while (p) {
            p = 0;
            for (int i = 0; i < path.size(); ++i) {
               if (tim[path[i].l] > tim[path[i].r] + path[i].len) {
                  tim[path[i].l] = tim[path[i].r] + path[i].len;
                  p = 1;
               }
               if (path[i].len > 0 && tim[path[i].r] > tim[path[i].l] + path[i].len) {
                  tim[path[i].r] = tim[path[i].l] + path[i].len;
                  p = 1;
               }
            }
            if (tim[st] < 0) {
               // printf("%d\n", tim[st]);
               p = 1; break;
            }
         }
         if (p) break;
      }
      if (p) printf("YES\n");
      else printf("NO\n");
   }
   return 0;
}