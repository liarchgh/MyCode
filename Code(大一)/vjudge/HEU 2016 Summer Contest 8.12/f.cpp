#include <cstdio>
#include <cstring>

int n,piao[25],ans[25],zong;
void zhao(int x){
    int a=x,sum=0;
    for(int i=0;x;++i){
        if(x&1) sum+=piao[i];
        x>>=1;
    }
    if(sum<=zong>>1) return;
    x=a;
    for(int i=0;x;++i){
        if(x&1){
            if(sum-piao[i]<=zong>>1) ++ans[i];
        }
        x>>=1;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(ans,0,sizeof(ans));
        zong=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&piao[i]);
            zong+=piao[i];
        }
        for(int i=1;i<(1<<n);++i) zhao(i);
        printf("%d",ans[0]);
        for(int i=1;i<n;++i) printf(" %d",ans[i]);
        putchar('\n');
    }
    return 0;
}
