#include <cstdio>

int n,d[2005][2005],vis[2005],ans[2005];
char ss[2005][9];
int pan(int a,int b){
    int sum=0;
    for(int i=0;i<7;++i){
        if(ss[a][i]!=ss[b][i]) ++sum;
    }
    return sum;
}
int main(){
    while(scanf("%d",&n),n){
            getchar();
        for(int i=0;i<n;++i){
                vis[i]=0;
                d[i][i]=0;
            gets(ss[i]);
            for(int ii=0;ii<i;++ii){
                d[ii][i]=d[i][ii]=pan(ii,i);
            }
            ans[i]=d[0][i];
        }
        int pre=0;vis[0]=1;
        for(int iiiii=0;iiiii<n-2;++iiiii){
            int mx=0;
            for(int i=0;i<n;++i){
                if(vis[i]) continue;
                if(vis[mx]) mx=i;
                else if(ans[i]<ans[mx]) mx=i;
                }
            vis[mx]=1;
            for(int i=0;i<n;++i){
                if(vis[i]) continue;
                if(d[mx][i]<ans[i]) ans[i]=d[mx][i];
            }
            }
            int len=0;
            for(int i=0;i<n;++i){
                len+=ans[i];
            }
            printf("The highest possible quality is 1/%d.\n",len);
    }
    return 0;
}
