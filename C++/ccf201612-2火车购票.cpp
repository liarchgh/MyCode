#include <cstdio>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mx = 100;
int piao[105] = {0};

int find_p(int x){
   for(int i = 0; i < mx; ++i){
      if(!piao[i] && (i + x - 1) / 5 == i / 5){
         int p = 1;
         for(int j = i; j < i + x; ++j){
            if(piao[j]) p = 0;
         }
         if(p) return i;
      }
   }
   return -1;
}

int main(){
   int n, p;
   scanf("%d", &n);
   while(n--){
      scanf("%d", &p);
      int now = find_p(p);
      if(now >= 0){
         for(int i = 0; i < p - 1; ++i){
            piao[i + now] = 1;
            printf("%d ", i + now + 1);
         }
         piao[now + p - 1] = 1;
         printf("%d\n", p + now);
      }
      else{
         for(int i = 0; i < mx && p > 0; ++i){
            if(!piao[i]){
               if(p > 1){
                  piao[i] = 1;
                  printf("%d ", i + 1);
               }
               else{
                  printf("%d\n", i + 1);
               }
               --p;
            }
         }
      }
   }
   return 0;
}