#include <cstdio>
#include <cmath>

int main() {
    int t,ty,n,m;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d",&ty,&n,&m);
        --n,--m;
        switch(ty) {
            case 1:
                if((!(n&1)) && (!(m&1))) printf("G\n");
                else printf("B\n");
                break;
            case 2:
                if(n==m) printf("G\n");
                else printf("B\n");
                break;
            case 3:
                if(((n+m)%3)) {
                    printf("D\n");
                    }
                else {
                    if(n==m) printf("G\n");
                    else if(n-m==1 || m-n==1) printf("B\n");
                    else printf("D\n");
                    }
                break;
            case 4:
                if(n<m){
                    int t=n;n=m;m=t;
                }
                int x=n-m;
                if((int)(x*(sqrt((double)5)+1)/2.0)==m) printf("G\n");
                else printf("B\n");
                break;
            }
        }
    return 0;
    }
