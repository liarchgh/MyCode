#include <cstdio>
#include <algorithm>
#include <cstring>


using namespace std;

int main(){
    int t,n,m,pi,a;
    double d[10005],b,p;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<10005;++i) d[i]=0.0;
        d[0]=1.0;
        scanf("%lf%d",&p,&n);
        for(int i=0;i<n;++i){
            scanf("%d%lf",&a,&b);
            for(int j=10005;j>=1;--j){
                if(j>=a);
                    d[j]=max(d[j],d[j-a]*(1-b));
            }
        }
        int ans=10004;
        while(d[ans]<=1-p) --ans;
        printf("%d\n",ans);
    }
    return 0;
}
