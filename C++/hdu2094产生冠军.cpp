// #include <ctime>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// long long bet = time(NULL);
const int mx = 1010;
int father[mx];
map<string, int>name;
vector<pair<int, int> >edge;

int find_father(int x) {
   if (father[father[x]] != father[x]) {
      father[x] = find_father(father[x]);
   }
   return father[x];
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
   freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
   int n;
   char nam1[999], nam2[999];
   while (scanf("%d", &n), n) {
      name.clear();
      edge.clear();
      int mar[n];//用来记录后边每条边是否去除掉
      memset(mar, 0, sizeof(mar));
      for (int i = 0; i < n; ++i) father[i] = i;
      getchar();
      for (int i = 0; i < n; ++i) {
         scanf("%s%s", nam1, nam2);
         
         if (name.find(nam1) == name.end()) name[nam1] = name.size() - 1;
         if (name.find(nam2) == name.end()) name[nam2] = name.size() - 1;
         edge.push_back(make_pair(name[nam1], name[nam2]));
         
         father[find_father(name[nam2])] = find_father(name[nam1]);
         
      }
      
      int p = 0;
      for (int i = 0; i < name.size() - 1; ++i) {
         // printf("%d ", find_father(i));
         if (find_father(i) != find_father(i + 1)) {
            printf("No\n");
            p = 1;
            break;
         }
      }
      
      if (p) continue;
      p = 2;
      while (p){
         //printf("%d ", p);
         int ark[n], nc_num = 0;//ark标记那些节点不可以去掉
         memset(ark, 0, sizeof(ark));
         for (int i = 0; i < edge.size(); ++i) {
            if (!mar[edge[i].first]) ark[edge[i].second] = 1;
         }
         int num = 0;//存放这一次要去掉的节点的个数
         for (int i = 0; i < name.size(); ++i) {
            if (!ark[i] && !mar[i]) {
               ++num;
               mar[i] = 1;
            }
            if (mar[i]) ++nc_num;
         }
         if (p == 2) {
            if (num != 1) {
               printf("No\n");
               p = 0;
            }
            else p = 1;
         }
         else if (!num) {
            if (nc_num == name.size()) {
               printf("Yes\n");
               p = 0;
            }
            else {
               printf("No\n");
               p = 0;
            }
         }
         else p = 1;
         // if(time(NULL) - bet > 5000) return 0;
      }
   }
   return 0;
}