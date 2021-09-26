#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
    if((double)a.second/a.first > (double)b.second/b.first) return true;
    if((double)a.second/a.first == (double)b.second/b.first && a.second>b.second) return true;
    return false;
}

void yue(int &x,int &y){
    int a=x,b=y;
    while(b){
        int t=b;
        b=a%b;
        a=t;
    }
    x/=a;
    y/=a;
}
int main(){
    int n,k;
    pair<int,int>a[50005];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a,a+n,cmp);
    int x=0,y=0;
    for(int i=0;i<k;++i){
        x+=a[i].first;
        y+=a[i].second;
    }
    yue(x,y);
    printf("%d/%d\n",y,x);
    return 0;
}
