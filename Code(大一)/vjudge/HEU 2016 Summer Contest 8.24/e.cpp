//很简单的利用next数组的题 然而才开始不会 看了解析后又把next数组命名为char类型 T^T 不讲道理地溢出了。。。。
#include <cstdio>

char ss[1000006];
int nex[1000005];
int main(){
    int n,th=1;
    while(scanf("%d",&n),n){
        getchar();
        gets(ss);
        nex[0]=0;
        int k=0;
        for(int q=1;q<n;++q){
            while(k>0 && ss[k]!=ss[q])
                k=nex[k-1];
            if(ss[k]==ss[q]) ++k;
            nex[q]=k;
        }
        printf("Test case #%d\n",th++);
        for(int i=1;i<n;i++){
            int l=i+1-nex[i];
            if(l!=i+1 && (i+1)%l==0){
                printf("%d %d\n",i+1,(i+1)/l);
            }
        }
        printf("\n");
    }
    return 0;
}
