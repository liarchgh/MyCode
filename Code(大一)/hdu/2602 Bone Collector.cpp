//最基础的01背包 然而我又忘了24行j循环时的下限
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,v,d[1005],val[1005],vi[1005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(d,0,sizeof(d));
        memset(val,0,sizeof(val));
        memset(vi,0,sizeof(vi));
        scanf("%d%d",&n,&v);
        for(int i=0;i<n;++i){
            scanf("%d",&val[i]);
        }
        for(int i=0;i<n;++i){
            scanf("%d",&vi[i]);
        }
        for(int i=0;i<n;++i){
            for(int j=v;j>=vi[i];--j){
                d[j]=max(d[j],d[j-vi[i]]+val[i]);
            }
        }
        printf("%d\n",d[v]);
    }
    return 0;
}
