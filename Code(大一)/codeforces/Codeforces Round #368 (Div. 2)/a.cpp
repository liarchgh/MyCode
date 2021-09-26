#include <cstdio>

int main(){
    int n,m,ans=0;
    char c;
    scanf("%d%d",&n,&m);getchar();
    for(int i=0;i<m*n;++i){
        c=getchar();getchar();
        if(ans) continue;
        if(c!='W' && c!='B' && c!='G') ans=1;
    }
    if(ans) printf("#Color\n");
    else printf("#Black&White\n");
    return 0;
}
