//吓死了 变量fei用int会溢出
#include <cstdio>

using namespace std;

int a,b,n,m,c[100005],has[100005],nex[100005];
int zhao(int x){
    if(x==n || has[x]<c[x]) return x;
    return nex[x]=zhao(nex[x]);
}
int main(){
    long long t;
    scanf("%I64d",&t);
    while(t--){
        long long int fei=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            scanf("%d",&c[i]);
            has[i]=0;
            nex[i]=i+1;
        }
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            --a;
            while(a<n && b>c[a]-has[a]){
                b-=c[a]-has[a];
                has[a]=c[a];
                a=zhao(a);
            }
            if(a>=n) fei+=b;
            else has[a]+=b;
        }
        printf("%I64d\n",fei);
        for(int i=0;i<n-1;++i){
            printf("%d ",has[i]);
        }
        printf("%d\n",has[n-1]);
    }
    return 0;
}
