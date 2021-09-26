//一看数据量就直接暴力做了-_-
#include <cstdio>
#include <cstring>

int n,m,a[22],d[1100000];
int main(){
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&m);
        memset(d,0,sizeof(d));
        for(int i=0;i<m;++i){
            scanf("%d",&a[i]);
            for(int ii=1;ii<(1<<m);++ii){
                if(ii&(1<<i)){
                    d[ii]+=a[i];
                }
            }
        }
        int ans=0;
        for(int i=1;i<(1<<m);++i){
            if(d[i]>n) continue;
            if(d[ans]<d[i]) ans=i;
        }
        for(int i=0;i<m;++i){
            if((1<<i)&ans){
                printf("%d ",a[i]);
            }
        }
        printf("sum:%d\n",d[ans]);
    }
    return 0;
}
