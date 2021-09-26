#include <cstdio>
#include <cstring>

using namespace std;

const int inf=200005;
int en[inf],vis[inf],g[inf];//en存每个点及区间和 vis存每个点下边是否还有未更新的点 g存每个区间开多少次方 -1表示>=7直接变成1
void pushup(int x){//更新en[x]
    en[x]=en[x<<1]+en[x<<1|1];
}
void pushd(int x){//将g数组向下退一层
    if(!g[x] || g[x]==-1) return;
    vis[x]=1;
    g[x<<1]+=g[x];
    g[x<<1|1]+=g[x];
    g[x]=0;
}
void jianshu(int l,int r,int x){
    if(l==r) scanf("%d",&en[x]);
    else{
        int mid=(l+r)>>1;
        jianshu(l,mid,x<<1);
        jianshu(mid+1,r,x<<1|1);
        pushup(x);
    }
}
void weapon(int l,int r,int ql,int qr,int x){
    if(l>qr || r<ql || g[x]==-1) return;
    vis[x]=1;
    if(l>=ql && r<=qr){
        ++g[x];
        return;
    }
    if(g[x]){
        pushd(x);
    }
    int mid=(l+r)>>1;
    weapon(l,mid,ql,qr,x<<1);
    weapon(mid+1,r,ql,qr,x<<1|1);
}
int mian(){
    int n,m,l,r,q;
    while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
        memset(g,0,sizeof(g));
        jianshu(1,n,1);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&q,&l,&r);
            if(q){
                cha(1,n,l,r,1);
            }
            else {
                weapon(1,n,l,r,1);
            }
        }
    }
    return 0;
}
