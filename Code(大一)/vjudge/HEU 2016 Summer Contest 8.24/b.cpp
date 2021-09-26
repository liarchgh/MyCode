//第二道KMP 同样是卡在了循环处 原来循环也和求next数组类似啊
#include <cstring>
#include <cstdio>

using namespace std;

char w[10005],t[1000005];
int main(){
    int T,next[10005],wl,tl;
    scanf("%d",&T);getchar();
    while(T--){
        gets(w);gets(t);
        wl=strlen(w);tl=strlen(t);
        memset(next,0,sizeof(next));
        int k=0,q;
        for(q=1;q<wl;++q){
            while(k>0 && w[k]!=w[q]){
                k=next[k-1];
            }
            if(w[k]==w[q]) ++k;
            next[q]=k;
            //printf("%d %d\n",k,q);
        }
        int ans=0;q=0;
        for(int i=0;i<tl;++i){
            while(q>0 && w[q]!=t[i]) q=next[q-1];
            if(w[q]==t[i]) ++q;
            if(q==wl){
                ++ans;
                q=next[q-1];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
