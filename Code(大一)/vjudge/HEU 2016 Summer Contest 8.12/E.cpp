#include <cstdio>
#include <algorithm>

using namespace std;

int bing[1005]={0};
int n,d,k,x,x1;
bool jia(int ji,int x){
    while(ji || x){
        if((ji&1) < (x&1)) break;
        ji>>=1;x>>=1;
    }
    if(x) return false;
    return true;
}
int zhao(int ji,int sta,int k){//ji为二进制表示当前已选的病毒 sta表示上一个病毒的位置 其下一个亦是此次病的的起始位置 k表示还可以选几个病毒
        int ans=0;
    if(k>0 && sta>=d) return 0;
    if(k<=0){
        for(int i=0;i<n;++i){
            if(jia(ji,bing[i])) ++ans;
        }
        return ans;
    }
    for(int i=sta+1;i<=d;++i){
        ans=max(zhao(ji|1<<i,i,k-1),ans);
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&n,&d,&k);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        while(x--){
            scanf("%d",&x1);
            bing[i]|=1<<x1;
        }
    }
    printf("%d\n",zhao(0,-1,k));
    return 0;
}
