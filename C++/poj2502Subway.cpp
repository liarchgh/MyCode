//不知道为什么声明大小为变量的数组不允许直接在大括号里初始化 可以确定其大小一定比大括号里的数多的
#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>
// #include <ctime>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const int mx = 205, inf = 99999999.0;
pair<int, int>st, sc;
float dis[mx][mx];
vector<pair<int, int> >no;
// long long now = time(NULL);

void cal_dis(int f, int x) {
   for (int i = 0; i < x; ++i) {
      dis[i][x] = dis[x][i] = sqrt(((float)no[i].first - no[x].first) * (no[i].first - no[x].first) + (no[i].second - no[x].second) * (no[i].second - no[x].second)) / 10000 * 60;
   }
   if (f) {
      dis[x - 1][x] = dis[x - 1][x] = dis[x - 1][x] / 4;
   }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("/home/ls/Downloads/Code/in.txt", "r", stdin);
   freopen("/home/ls/Downloads/Code/out.txt", "w", stdout);
#endif
   // printf("1\n");
   scanf("%d%d%d%d", &st.first, &st.second, &sc.first, &sc.second);
   no.push_back(st);
   no.push_back(sc);
   cal_dis(0, no.size() - 1);
   pair<int,int>a;
   while (scanf("%d%d", &a.first, &a.second) != EOF) {
      no.push_back(a);
      cal_dis(0, no.size() - 1);
      while (scanf("%d%d", &a.first, &a.second), a.first != -1 || a.second != -1) {
         no.push_back(a);
         cal_dis(1, no.size() - 1);
      }
      // if(time(NULL) - now > 5000) return 0;
   }
   int n = no.size();
   int next = 0, mar[n];
   memset(mar, 0, sizeof(mar));
   float lowst[no.size()];
   for(int i = 0; i < no.size(); ++i){
      lowst[i] = inf;
   }
   lowst[0] = 0.0;
   while(next >= 0 && next != 1){
      int x = next;
      next = -1;
      mar[x] = 1;
      for(int i = 0; i < no.size(); ++i){
         if(!mar[i] && lowst[i] > lowst[x] + dis[min(i, x)][max(i, x)]){
            lowst[i] = lowst[x] + dis[min(i, x)][max(i, x)];
         }
         if(!mar[i] && (next < 0 || lowst[i] < lowst[next])) next = i;
      }
      // if(time(NULL) - now > 5000) return 0;
      // printf("1\n");
   }
   // for(int i = 0; i < no.size(); ++i) printf("%f\n", lowst[i]);
   // for(int i = 0; i < no.size(); ++i){
   //    for(int j = 0; j < no.size(); ++j){
   //       printf("%f\t", dis[i][j]);
   //    }
   //    putchar('\n');
   // }
   printf("%.0f\n", lowst[1]);
   return 0;
}