#include <cstdio>

int main(){
    long long a;
    int t;
    scanf("%d",&t);
    while(t--){
            scanf("%I64d",&a);
    int ans=0;
    while(!(a%2)) {a/=2;++ans;}
    if(ans&1) printf("Second Box\n");
    else printf("First Box\n");}
    return 0;
}
