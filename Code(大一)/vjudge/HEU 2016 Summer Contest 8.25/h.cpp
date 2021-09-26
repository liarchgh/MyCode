//第一道哈希的题目 不难 又是细节 果然要通过做题来熟练啊啊 26行应该是 i<n-1 一开始写的n
#include <cstdio>
#include <cstring>

using namespace std;

char ss[16000005];
int xu[150],vis[16000005];
int bas;
int main(){
    int n,nc;
    scanf("%d%d",&n,&nc);getchar();
    gets(ss);
    memset(xu,-1,sizeof(xu));
    int len=strlen(ss);
    for(int i=0,th=0;th<nc && i<len;++i){
        if(xu[ss[i]]==-1){
            xu[ss[i]]=th++;
            //printf("%d\n",th);
        }
    }
    long long t=0;
    int ans=0;
    bas=1;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<len;++i){
        if(i<n-1){
            t=t*nc+xu[ss[i]];
            bas*=nc;
        }
        else{
            t=t%bas;
            t=t*nc+xu[ss[i]];
            if(!vis[t]){
                ++ans;
                vis[t]=1;
            }
            //printf("%d\n",t);
        }
    }
    printf("%d",ans);
    return 0;
}
