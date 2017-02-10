#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
   int n, a = -1, b, ans = -1;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i){
      if(a >= 0){
         scanf("%d", &b);
         ans = max(ans, abs(b - a));
         a = b;
      }
      else{
         scanf("%d", &a);
      }
   }
   printf("%d\n", ans);
   return 0;
}