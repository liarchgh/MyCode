#include <cstdio>
#include <cmath>

int main() {
    int n,a,p,b;
    while(scanf("%d",&n)!=EOF) {
        p=1;
        for(int i=0; i<n; ++i) {
            scanf("%d",&a);
            if(p) {
                b=sqrt(a);
                if(b*b!=a) p=0;
                }
            }
        if(p) printf("Yes\n");
        else printf("No\n");
        }
    return 0;
    }
