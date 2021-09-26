#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
   int n;
   scanf("%d",&n);
   int so[n+1],p=1,a,b,vis[n+1]={0};
   for(int i=1;i<=n;++i){
       scanf("%d",&so[i]);
       ++vis[i];
       ++vis[so[i]];
       if(vis[so[i]]>=2 || vis[i]>=2){
           p=0;
           continue;
       }
   }
   a=so[1];
   while(a!=1){

       a=so[a];
   }
   return 0;
}
