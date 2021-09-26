//54行的判断条件一直没有想起来 GG
#include <cstdio>

int main() {
    int n,qx,qy;
    scanf("%d",&n);
    long long int g[n][n];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            scanf("%I64d",&g[i][j]);
            if(0==g[i][j]) {
                qx=i;
                qy=j;
            }
        }
    }
    if(n==1) {
        printf("1\n");
        return 0;
    }
    int stax=0;
    if(stax==qx) ++stax;
    long long sum=0;
    for(int i=0; i<n; ++i) {
        sum+=g[stax][i];
    }
    long long s1,s2;
    s1=0;
    for(int i=0; i<n; ++i) {
        s1+=g[qx][i];
    }
    g[qx][qy]=sum-s1;
    for(int j=0; j<n; ++j) {
        s1=0;
        s2=0;
        for(int i=0; i<n; ++i) {
            s1+=g[i][j];
            s2+=g[j][i];
        }
        if(s1!=sum || s2!=sum) {
            printf("-1\n");
            return 0;
        }
    }
    s1=0;
    s2=0;
    for(int i=0; i<n; ++i) {
        s1+=g[i][i];
        s2+=g[i][n-i-1];
    }
    if(s1!=sum || s2!=sum) {
        printf("-1\n");
        return 0;
    }
    if(g[qx][qy]>0)
    printf("%I64d\n",g[qx][qy]);
    else printf("-1\n");
    return 0;
}
