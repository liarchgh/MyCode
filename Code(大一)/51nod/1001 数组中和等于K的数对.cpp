//×¢ÒâÏ¸½Ú°¡°¡°¡°¡°¡°¡°¡°¡
#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
int a[50005];
bool zhao(int sta,int x){
    int l=sta+1,r=n-1,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(a[mid]<x) l=mid+1;
        else if(a[mid]>x) r=mid-1;
        else {return true;}
    }
    return false;
}
int main(){
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int x,sum=0;
    for(int i=0;i<n-1 && a[i]<=k/2;++i){
        x=k-a[i];
        if(x==a[i]){
            if(i>0 && a[i-1]==a[i]) continue;
            if(a[i+1]==a[i]) {++sum;printf("%d %d\n",a[i],x);}
        }
        else if(zhao(i,x)){
            ++sum;
            printf("%d %d\n",a[i],x);
        }
    }
    if(!sum) printf("No Solution\n");
    return 0;
}
