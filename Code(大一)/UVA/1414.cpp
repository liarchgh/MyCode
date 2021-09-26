//想了半天都没想出来 差点以为和二分图匹配没关系了 看了解析 两条边相交的话一定会有两条新的边长度和更短 这样更新下那就行了 crazy 不知道为什么我的这个代码就是一直WA 没什么漏洞啊 必须要用KM么？！？！？
//思路果然没错T^T 一直WA是因为它有多组数据 而且输出间要有空行
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx=105;
int n,ant[mx][2],tree[mx][2],ans[mx],vis[mx];
double dis[mx][mx];
int chacheng(int x[],int y[],int j[]) {
   int xj[2] = {x[0] - j[0], x[1] - j[1]},
               yj[2] = {y[0] - j[0], y[1] - j[1]};
   return xj[0] * yj[1] - xj[1] * yj[0];
}
bool jiao(int x,int y) {
   long long a = chacheng(ant[y], tree[ans[x]], ant[x]),
             b = chacheng(tree[ans[y]], tree[ans[x]], ant[x]),
             c = chacheng(ant[x], tree[ans[y]], ant[y]),
             d = chacheng(tree[ans[x]], tree[ans[y]], ant[y]);
   if(a * b <= 0 && c * d <= 0) return true;
   return false;
}
bool pan(int x) {
   for(int i = 0; i < x; ++i) {
      if(jiao(x, i)) {
         swap(ans[x], ans[i]);
         pan(i);
         pan(x);
         return true;
      }
   }
   return false;
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("C:\\in.txt", "r", stdin);
   freopen("c:\\out.txt", "w", stdout);
#endif
   int th = 0;
   while(scanf("%d", &n) != EOF) {
      for(int i = 0; i < n; ++i) {
         scanf("%d%d", &ant[i][0], &ant[i][1]);
      }
      for(int i = 0; i < n; ++i) {
         scanf("%d%d", &tree[i][0], &tree[i][1]);
      }
      // for(int i = 0; i < n; ++i) {
      // for(int j = 0; j < n; ++j) {
      // dis[i][j] = -sqrt(((double)ant[i][0] - tree[j][0]) * (ant[i][0] - tree[j][0]) + (ant[i][1] - tree[j][1]) * (ant[i][1] - tree[j][1]));
      // }
      // }
      //memset(ans, -1, sizeof(ans));
      memset(vis, 0, sizeof(vis));
      int p=1;
      for(int i = 0; i < n; ++i) ans[i] = i;
      while(p) {
         //printf("%d", p);
         p=0;
         for(int i = 0; i < n; ++i) {
            //for(int j = 0; j < n; ++j){
            //if(!vis[j]){
            //vis[j] = 1;
            if(pan(i)) {
               p=1;//printf("\t%d",i);
            }
            //printf("      %d %d\n",n,i,ans[i]);
            //}
            //}
         }
      }
      for(int i = 0; i < n; ++i) {
         printf("%d\n",ans[i]+1);
      }
      if(th) printf("\n");
      else ++th;
   }
   return 0;
}

// #include <cstdio>
// #include <cstring>
// #include <algorithm>
// #include <queue>
// #include <cmath>

// using namespace std;

// int main(){
// return 0;
// }
