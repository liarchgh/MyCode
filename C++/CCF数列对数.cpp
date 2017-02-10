#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

const int mx = 1005;
int num[mx];

int main(){
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; ++i){
      scanf("%d", &num[i]);
   }
   sort(num, num + n);
   int ans = 0;
   for(int i = 0; i < n - 1; ++i){
      for(int j = i + 1; j < n; ++j){
         if(abs(num[i] - num[j]) == 1) ++ans;
      }
   }
   printf("%d\n", ans):
   return 0;
}