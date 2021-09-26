#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,m,d[25005],sum,a;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        sum=0;
        memset(d,0,sizeof(d));
        while(m--){
            scanf("%d",&a);
            sum+=a;
            for(int i=25000;i>=a;--i){
                d[i]=max(d[i],d[i-a]+a);
            }
        }
        printf("%d\n",sum-d[sum>>1]*2);
    }
    return 0;
}
