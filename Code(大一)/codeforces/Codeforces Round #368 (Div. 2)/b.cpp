//细节细节 要注意啊！！！直接排序就好 不用循环
#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int x,y,l;
}ed[100005];
bool cmp(edge a,edge b){
    return a.l<b.l;
}
int n,m,k,st[100005]={0},cang[100005],vis[100005]={0};
int main(){
    int a,b,c;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&ed[i].l);
        vis[a]=vis[b]=1;
        if(a>b){
            int t=a;a=b;b=t;
        }
        ed[i].x=a;ed[i].y=b;
    }
    sort(ed,ed+m,cmp);
    int p=0;
    for(int i=0;i<k;++i){
        scanf("%d",&cang[i]);
        if(vis[cang[i]]) p=1;
        st[cang[i]]=1;
    }
    if(!p){
        printf("-1\n");
        return 0;
    }
    //printf("11111\n");
    for(int i=0;i<m;++i){
            //printf("%d %d %d\n%d %d\n",ed[i].x,ed[i].y,ed[i].l,st[ed[i].x],st[ed[i].y]);
        if(st[ed[i].x] + st[ed[i].y] ==1){
            printf("%d\n",ed[i].l);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
