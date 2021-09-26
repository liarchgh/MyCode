//真的不太好理解啊 匈牙利算法
#include <cstdio>
#include <cstring>

using namespace std;

const int mx=105;
int n,m,k,g[mx][mx],vis[mx],link[mx];

int dfs(int x){
    for(int i=1;i<m;++i){//依次遍历右边的点
        if(g[x][i] && !vis[i]){
            vis[i]=1;//以后就不用走这个点了 因为在另一端已经找不到可增广路了
            if(link[i]==-1 || dfs(link[i])){//如果右边的这个点连接的有点 看一下能不能在另一头找到一个能扩展的点 即找一条可增广路
                link[i]=x;//这个右边的点连上传进来的左边的点
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int a,b,c;
    while(scanf("%d",&n),n){
        memset(g,0,sizeof(g));
        memset(link,-1,sizeof(link));
        scanf("%d%d",&m,&k);
        for(int i=0;i<k;++i){
            scanf("%d%d%d",&a,&b,&c);
            g[b][c]=1;
        }
        int ans=0;
        for(int i=1;i<n;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)){
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
