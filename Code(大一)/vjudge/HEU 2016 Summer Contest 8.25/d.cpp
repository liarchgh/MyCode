//就直接暴力就可以 才开始听了也不会 果然还是要写一写才会
#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int su[1100],nsu,vis[1100];
int bi(int a,int b){
    int n=0;
    for(int i=0;i<4;++i){
        if(a%10==b%10){
            ++n;
        }
        a/=10;b/=10;
    }
    if(n==3) return 1;
    return 0;
}
int chuan(int a,int b){
    queue<pair<int,int> >q;
    q.push({0,a});
    while(!q.empty()){
        int n=q.front().first,aa=q.front().second;
        //printf("    %d %d\n",n,aa);
        q.pop();//printf("    %d %d\n",n,aa);
        if(aa==b) {printf("%d\n",n);return 0;}
        for(int i=0;i<nsu;++i){
            if(!vis[i] && bi(su[i],aa)) {q.push({n+1,su[i]});vis[i]=1;}
        }
    }
    printf("Impossible\n");
    return 0;
}
int main(){
    nsu=0;
    for(int i=3,ns=1,ss[1500]={2};i<10000;++i){
        int j;
        for(j=0;j<ns;++j){
            if(!(i%ss[j])) break;
        }
        if(j==ns) {
            ss[ns++]=i;
            if(i>=1000) su[nsu++]=i;
            //printf("%d\n",nsu);
        }
    }
    int n,a,b;
    scanf("%d",&n);
    while(n--){
            memset(vis,0,sizeof(vis));
        scanf("%d%d",&a,&b);
        chuan(a,b);
    }
    return 0;
}
