//POJ 2965 G++会TLE C++就会过
#include <cstdio>

int fan(int a,int n) {
    int num=0;
    for(int i=0; i<4; ++i) {
        for(int j=0; j<4; ++j) {
            if(a&(1<<(i*4+j))) {
                ++num;
                for(int x=0; x<4; ++x) {
                        n^=1<<(i*4+x);
                    if(x!=i)
                        n^=1<<(x*4+j);
                    }
                }
            }
        }
    //printf("%d\n",num);
    if(n) return 0;
    else return num;
    }
int main() {
    int n=0;
    char c;
    for(int i=0; i<4; ++i) {
        for(int j=0; j<4; ++j) {
            c=getchar();
            switch(c) {
                case '+':
                    n|=1<<(i*4+j);
                    break;
                }
            }
        getchar();
        }
    //n=15;
    //printf("%d\n",n);
    int ans,x,zans,zx=20;
    for(ans=1; ans<(1<<16); ++ans) {
        x=fan(ans,n);
        if(x) {
            if(zx>x) {
                zx=x;
                zans=ans;
                }
            }
        }
    printf("%d\n",zx);
    ans=zans;
    for(int i=1; i<=4; ++i) {
        for(int j=1; j<=4; ++j) {
            if(ans&(1<<((i-1)*4+j-1))) {
                printf("%d %d\n",i,j);
                }
            }
        }
    return 0;
    }
