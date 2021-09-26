//不用vis数组记录是否走过 多余 只要能联通就不用走 否则就走
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int x,y,l;
}ed[105];
int n,m,fa[105];
int zhao(int x){
    if(fa[x]==x) return x;
    return fa[x]=zhao(fa[x]);
}
bool cmp(edge a,edge b){
    if(a.l<b.l) return true;
    if(a.l>b.l) return false;
    if(a.x<b.x) return true;
    if(a.x==b.x && a.y<b.y) return true;
    return false;
}
void jie(int x){
    for(int i=2;i<=m;++i){
        if(zhao(i)!=zhao(1)) {printf("?\n");return;}
    }
    printf("%d\n",x);
}
int main(){
    int a,b,c;
    while(scanf("%d%d",&n,&m),n){
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&ed[i].x,&ed[i].y,&ed[i].l);
            if(ed[i].x>ed[i].y){
                int t=ed[i].x;
                ed[i].x=ed[i].y;
                ed[i].y=t;
            }
        }
        for(int i=0;i<=m;++i){
                fa[i]=i;//vis[i]=0;
        }
        sort(ed,ed+n,cmp);
        int len=0,l1,l2;
        for(int i=0;i<n;++i){
            l1=zhao(ed[i].x);l2=zhao(ed[i].y);
            if(zhao(l1)==zhao(l2)) continue;
            //if(!vis[ed[i].x] || !vis[ed[i].y]){
                //vis[ed[i].x]=vis[ed[i].y]=1;
            len+=ed[i].l;
            if(l1>l2) swap(l1,l2);
            fa[l2]=fa[l1];
            //}
        }
        jie(len);
    }
    return 0;
}
