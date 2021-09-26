#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

struct no{
    int ind,x,y;
}nod[105];
int main(){
    int m,n;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d%d",&nod[i].ind,&nod[i].x,&nod[i].y);
            if(nod[i].y<nod[0].y) swap(nod[i],nod[0]);
            else if(nod[i].y==nod[0].y && nod[i].x<nod[0].x) swap(nod[i],nod[0]);
        }
        no x,y,x1;
        for(int i=0;i<n-1;++i){
                x=nod[i];x1=nod[i+1];
            for(int j=i+2;j<n;++j){
                y=nod[j];
                if((y.x-x.x)*(x1.y-x.y)-(y.y-x.y)*(x1.x-x.x)>0) {swap(nod[i+1],nod[j]);x1=nod[i+1];}
                else if((y.x-x.x)*(x1.y-x.y)-(y.y-x.y)*(x1.x-x.x)==0){
                    if((y.x-x.x)*(y.x-x.x)+(y.y-x.y)*(y.y-x.y)<(x1.y-x.y)*(x1.y-x.y)+(x1.x-x.x)*(x1.x-x.x)) swap(nod[i+1],nod[j]);
                }
            }
        }
            printf("%d",n);
        for(int i=0;i<n;++i){
            printf(" %d",nod[i].ind);
        }
        putchar('\n');
    }
    return 0;
}
