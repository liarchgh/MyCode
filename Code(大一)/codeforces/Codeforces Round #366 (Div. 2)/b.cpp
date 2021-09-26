#include<cstdio>

int main() {
    int n,a[100005],t;
    long long sum=0;
    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d",&t);
        //printf("%d",t)
        sum+=t-1;
        a[i]=sum;
        }
    for(int i=0; i<n; ++i) {
            //printf("%d ",a[i]);
        if((a[i])&1)
            printf("1\n");
        else printf("2\n");
        }
    return 0;
    }
