#include <cstdio>

using namespace std;

char gg[1005][8];
int main(){
    int m;
    scanf("%d",&m);getchar();
    for(int i=0;i<m;++i){
        gets(gg[i]);
    }
    int p=0;
    for(int i=0;i<m;++i){
        for(int j=0;j<4;++j){
            if(gg[i][j]=='O' && gg[i][j+1]=='O'){
                gg[i][j]=gg[i][j+1]='+';
                p=1;
                break;
            }
        }
        if(p) break;
    }
    if(!p){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(int i=0;i<m;++i){
            puts(gg[i]);
        }
    }
    return 0;
}
