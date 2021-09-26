//应该是首道KMP算法的题 感觉就像用针尖在数字上跳舞一样 很神奇 只看了next数组的求法就来做了 没过 又看了怎么用next数组循环求答案 才行 少一点都不行啊
#include <cstdio>

int n,m,b[10005],a[1000005],k,next[10005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;++i){
            scanf("%d",&b[i]);
        }
        next[0]=0;
        int q,p=0;
        for(q=1;q<m;++q){
            while(p>0 && b[p]!=b[q]){
                p=next[p-1];
            }
            if(b[p]==b[q]) ++p;
            next[q]=p;
        }
        p=1;q=0;
        for(int i=0;i<n;++i){
            while(q>0 && b[q]!=a[i]) q=next[q-1];
            if(b[q]==a[i]) ++q;
            if(q==m){
                    printf("%d\n",i-m+2);
                p=0;break;
            }
        }
        if(p) printf("-1\n");
    }
    return 0;
}
