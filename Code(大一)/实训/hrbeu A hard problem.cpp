#include<cstdio>
int shu[1000][1000];
int main(){
    int a,b;
    shu[0][0]=1;
    printf("1\n");
    for(int i=1;i<10;++i){
            int j=0;
        for(;j<(i+2)/2;++j){
                shu[i][j]=shu[i-1][j]+shu[i-1][j-1];
                //if(shu[i][j]<=shu[i-1][j]) shu[i][j]=shu[i-1][j]-(1e9+7)+j;
            printf("%d ",shu[i][j]);
        }
        for(;j<i;++j){
            printf("%d ",shu[i][j]=shu[i][i-j]);
        }
        printf("%d\n",shu[i][i]=shu[i][0]);
    }
    return 0;
}
