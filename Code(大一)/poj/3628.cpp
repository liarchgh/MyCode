//背包问题 然而可以直接暴力过-_-  不过网上的代码好像时间复杂度也要达到1<<n的级别
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,b,h[25],ans=0xfffffff,d[1100005]={0};
int main(){
    scanf("%d%d",&n,&b);
    for(int i=0;i<n;++i){
        scanf("%d",&h[i]);
        for(int j=1;j<(1<<n);++j){
            if(j&(1<<i)){
                d[j]+=h[i];
            }
        }
    }
    for(int j=0;j<(1<<n);++j){
        if(d[j]>=b) ans=min(ans,d[j]-b);
        if(!ans) break;
    }
    printf("%d\n",ans);
    return 0;
}
