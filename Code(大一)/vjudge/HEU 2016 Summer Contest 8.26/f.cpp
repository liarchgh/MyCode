#include <cstdio>

using namespace std;

char ss[200005];
int nex[200005];
int main(){
    int T,n,ans;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);getchar();
        ans=n;
        gets(ss);
        int k=0;
        nex[0]=0;
        for(int q=1;q<n;++q){
            while(k>0 && ss[k]!=ss[q]) k=nex[k-1];
            if(ss[k]==ss[q]) ++k;
            nex[q]=k;
            if(k) {++ans;ans%=10007;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
