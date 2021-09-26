#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 10005;
int aa[105], bb[105], dp0[mx], dp1[mx];//dp[i]为taste为i时对应的卡路里

int main(){
   #ifndef ONLINE_JUDGE
      freopen("C:\\in.txt", "r", stdin);
      //freopen("C:\\out.txt", "w", stdout);
   #endif
   int n, k, a[105], b[105], c[105], d[105];
   //printf("111\n");
   scanf("%d%d", &n, &k);
   for(int i = 0; i < n; ++i){
      scanf("%d", &a[i]);
   }
   for(int i = 0; i < n; ++i){
      scanf("%d", &b[i]);
   }
   int sc = 0, sd = 0, t, jiaa = 0, jiab = 0;
   for(int i = 0; i < n; ++i){
      t = a[i] - b[i] * k;
      if(t > 0){
         aa[sc++] = t;
      }
      else if(t < 0){
         bb[sd++] = t;
      }
      else{
         jiaa += a[i];
         jiab += b[i];
      }
   }
   memset(dp0, 0, sizeof(dp0));
   memset(dp1, 0, sizeof(dp1));
   for(int i = 0; i < sc; ++i){
      for(int j = mx; j >= 0; --j){
         if(dp1[j] || !j){
            dp1[j+aa[i]] = 1;
         }
      }
   }
   for(int i = 0; i < sd; ++i){
      for(int j = mx; j >= 0; --j){
         if(dp0[j] || !j){
            dp0[j+bb[i]] = 1;
         }
      }
   }
   
   printf("%d\n", dp[0]);
   return 0;
}
