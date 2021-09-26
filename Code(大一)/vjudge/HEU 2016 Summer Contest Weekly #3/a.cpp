#include <cstdio>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m){
        int t=n;
        n=m;
        m=t;
    }
    long long ans=0;
    while(n){
        int a1=m-(n+m)%5,
            a2=5-n%5;
        if(a1>0 && a2<=m && a1>=a2)
            ans+=(a1-a2)/5+1;
        --n;
    }
    printf("%lld\n",ans);
    return 0;
}
