//没敢试一试只求右边的情况 直接左右都求了
#include <cstdio>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a<b){
        printf("-1\n");return 0;
    }
    if(!(a%b)){
        int x=a/b;
        if(x&1){
            printf("%d.0\n",b);
            return 0;
        }
    }
    int x=a+b;
    int a1=x/b;
    if(a1&1) --a1;
    double ans1=(double)x/a1;
    x=a-b;
    a1=x/b;
    if(a1&1) --a1;
    double ans2=(double)x/a1;
    if(ans1>ans2) ans1=ans2;
    printf("%.9lf\n",ans1);
    return 0;
}
