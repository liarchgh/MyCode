#include <cstdio>
#include <cmath>

int main() {
    int a,b;
    double p = (1 + sqrt ( (double )5 ) ) / double(2);
    while(scanf("%d%d",&a,&b)!=EOF) {
        if(a>b) {
            int t=a;
            a=b;
            b=t;
            }
        int dis=b-a;
        if(a==(int)(p*dis)) printf("0\n");
        else printf("1\n");
        }
    return 0;
    }
