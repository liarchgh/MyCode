#include <cstdio>

int n,m,ro[1005],vis[1005],a,b;
int zhao(int x){
    if(ro[x]==x) return x;
    return x=zhao(ro[x]);
}
int main(){
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        for(int i=0;i<1005;++i){
            ro[i]=i;
        }
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            vis[a]=vis[b]=1;
            a=zhao(a);
            b=zhao(b);
            ro[a]=ro[b];
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            if(ro[i]==i) ++ans;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
