//就用寻常的最小生成树就过了 然而心中还是迷茫的 不太清楚为什么会过 为什么这个出来的最长边就是最小的最长边
#include <vector>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 504;
int n, father[mx];

int find_father(int x){
   if(father[father[x]] != father[x]){
      father[x] = find_father(father[x]);
   }
   return father[x];
}

void unit(int a, int b){
   father[father[a]] = father[b];
}

struct edge{
   int l, r, len;
   edge(int x, int y, int le){
      l = x;
      r = y;
      len = le;
   }
};

vector<edge>ed;

bool cmp_ed(edge a, edge b){
   return a.len < b.len;
}

int main(){
   #ifndef ONLINE_JUDGE
   freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
   freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
   #endif
   int t;
   scanf("%d", &t);
   while(t--){
      ed.clear();
      scanf("%d", &n);
      for(int i = 0, l; i < n; ++i){
         for(int j = 0; j < n; ++j){
            scanf("%d", &l);
            if(i < j)
               ed.push_back(edge(i, j, l));
            // printf("\t%d\n", l);
         }
      }
      sort(ed.begin(), ed.end(), cmp_ed);
      // for(vector<edge>::iterator it = ed.begin() + 1, t; it != ed.end(); ++it){
      //    if(it->l == (it - 1)->l && it->r == (it - 1)->r){
      //       t = it - 1;
      //       ed.erase(it);
      //       it = t;
      //    }
      // }
      int ans;
      for(int i = 0; i < n; ++i){
         father[i] = i;
      }
      for(vector<edge>::iterator it = ed.begin(); it != ed.end(); ++it){
         // printf("%d\n", it->len);
         if(find_father(it->l) != find_father(it->r)){
            unit(father[it->l], father[it->r]);
            ans = it->len;
         }
      }
      printf("%d\n", ans);
   }
   return 0;
}