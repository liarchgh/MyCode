#include <cstdio>

int main(){
    int m,a[200005],sum;
    while(scanf("%d",&m), m){
            sum=0;
    for(int i=0;i<m;++i){
        scanf("%d",&a[i]);
        sum^=a[i];
    }
    if(sum==0) printf("No\n");
    else
    {
        printf("Yes\n");
        for(int i=0;i<m;++i){
                int x=sum^a[i];
            if(x<=a[i]) printf("%d %d\n",a[i],x);
        }
    }
    }
    return 0;
}
