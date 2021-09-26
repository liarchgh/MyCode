#include <cstdio>

int main(){
    int t,x0,x1,i;
    while(scanf("%d",&i),i){
        x0=x1=0;
        while(!(i&1)) {i>>=1;++x0;}
        while(i&1) {i>>=1;++x1;}
        i|=1;
        --x1;++x0;
        while(x0>0) {i=i<<1;--x0;}
        while(x1>0) {i=i<<1|1;--x1;}
        printf("%d\n",i);
    }
    return 0;}
