#include <cstdio>

int main(){
    int t,n,p,sum,a;
    scanf("%d",&t);
    while(t--){
            sum=p=0;
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%d",&a);
            if(a > 1) ++p;
            sum ^= a;
        }
        if(p <1){
            if(n  & 1) printf("Brother\n");
            else printf("John\n");
        }
        else{
            if(sum) printf("John\n");
            else printf("Brother\n");
        }
    }
    return 0;
}
