//loading
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 100005;
struct edge{
   int l, r, len;
   bool operator<(edge x){return len < x.len;}
}ed[mx];
int father[mx];

int find_father(int x){
   if(father[x] != father[father[x]])
      father[x] = find_father(father[x]);
   return father[x];
}

int main(){
   int n, m, ans = 0;
   scanf("%d%d", &n, &m);
   for(int i = 0; i <= n; ++i) father[i] = i;
   for(int i = 0; i < m; ++i){
      scanf("%d%d%d", &ed[i].l, &ed[i].r, &ed[i].len);
   }
   sort(ed, ed + m);
   //for(int i = 0; i < m; ++i) 
     //    printf("%d %d %d %d\n", ed[i].l, ed[i].r, father[ed[i].l], father[ed[i].r]);
   for(int i = 0; i < m; ++i){
      if(find_father(ed[i].l) != find_father(ed[i].r)){
         printf("%d %d\n", ed[i].l, ed[i].r);
         ans += ed[i].len;
         father[father[ed[i].l]] = father[ed[i].r];
      }
   }
   printf("%d\n", ans);
   return 0;
}