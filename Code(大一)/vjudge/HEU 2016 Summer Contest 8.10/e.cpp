#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct no{
    int x,y;
}ver[1005];
int n,l;
double ans=0;
bool pan(no a,no b,no c){
    int x=(c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
    if(x>0) return true;
    else if(x==0 && abs(c.x-a.x)+abs(c.y-a.y)>abs(b.x-a.x)+abs(b.y-a.y)) return true;
    return false;
}
double juli(no a,no b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
    scanf("%d%d",&n,&l);
    for(int i=0;i<n;++i){
        scanf("%d%d",&ver[i].x,&ver[i].y);
        if(ver[i].y<ver[0].y || (ver[i].y==ver[0].y && ver[i].x<ver[0].x))
            swap(ver[i],ver[0]);
    }
    no sta=ver[0];
    for(int i=0;i<n;++i){
        if(i!=n-1)
        for(int j=0;j<n;++j){
            if(i==j || j==i+1) continue;
            if(pan(ver[i],ver[i+1],ver[j])) swap(ver[i+1],ver[j]);
        }
        ans+=juli(ver[(i+1)%n],ver[i]);
        //printf("%d %d %d %d %lf\n",ver[i].x,ver[i].y,ver[i+1].x,ver[i+1].y,ans);
        if(ver[i+1].x==sta.x && ver[i+1].y==sta.y) break;
    }
    ans+=3.14159265*2*l;
    //ans=2.5;
    printf("%.0lf\n",ans);
    return 0;
}
/*
4 1
1 0
2 0
1 1
2 1

*/
