#include <cstdio>

int n,s,e,a[5005],b[5005],c[5005],d[5005],x[5005],t[5005]={0};
int time(int i,int j){
    if(i<j) return x[j]-x[i]+d[i]+a[j];
    else if(i>j) return x[i]-x[j]+c[i]+b[j];
    else return 0;
}
int main(){
    scanf("%d%d%d",&n,&s,&e);
    for(int i=0;i<n;++i)
        scanf("%d",&x[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&c[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&d[i]);
    return 0;
}
