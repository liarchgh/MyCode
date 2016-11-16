//A掉了 是初始化的问题
#include <cstdio>
#include <cstring>
#include <fstream>
#include <map>
#include <string>
#include <iostream>

using namespace std;

// long long bet = time(NULL);
const int mx = 1010;
int flag[mx];
map<string, int>name;

int main() {
#ifndef ONLINE_JUDGE
   freopen("D:\\in.txt", "r", stdin);
   freopen("D:\\out.txt", "w", stdout);
#endif
   int n;
   string nam1, nam2;
   while (scanf("%d", &n), n) {
   	memset(flag, 0, sizeof(flag));
      name.clear();
      getchar();
      for (int i = 0; i < n; ++i) {
         cin >> nam1 >> nam2;
         // cout << nam1 << endl;
         if (name.find(nam1) == name.end()) name[nam1] = name.size() - 1;
         if (name.find(nam2) == name.end()) name[nam2] = name.size() - 1;
         flag[name[nam2]] = 1;
      }
      int ans = 0;
      for(int i = 0; i < name.size(); ++i){
        if(!flag[i]) ++ans;
      }
      if(ans == 1){
        printf("Yes\n");
      }
      else printf("No\n");
   }
   return 0;
}
