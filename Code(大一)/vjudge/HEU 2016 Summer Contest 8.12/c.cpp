#include <cstdio>

int main(){

int t,ans,a;
while(scanf("%d",&t),t){
        ans=0;
    while(t--){
        scanf("%d",&a);
ans^=a;
    }
    printf("%d\n",ans);
}
    return 0;}
