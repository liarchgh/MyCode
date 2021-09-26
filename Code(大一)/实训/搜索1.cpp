#include<cstdio>
#include<string.h>
int n;
char pic[100][100],vis[100][100];
int findlu(int x1,int y1){
    int i,x,y;
    char a[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    for(i=0;i<4;++i){
        x=x1+a[i][0];y=y1+a[i][1];
        if(vis[x][y]==3) return 1;
        if(vis[x][y]||x<0||x>n-1||y<0||y>n-1||(pic[x][y]=='#')) continue;
        if(findlu(x,y)) return 1;
        vis[x][y]=1;
    }
    return 0;
}
int main()
{
    int j,i,x1,y1,x2,y2;
    gets(pic[0]);
    n=strlen(pic[0]);
    for(i=1;i<n;++i)
        gets(pic[i]);
    for(i=0;i<n;++i)
    for(j=0;j<n;++j){
        switch(pic[i][j]){
        case 'A':x1=i;y1=j;vis[i][j]=1;break;
        case 'B':x2=i;y2=j;vis[x2][y2]=3;break;
        default:vis[i][j]=0;
        }
    }
    if(findlu(x1,y1))
        printf("Y");
    else printf("N");
    //getchar();
    return 0;
}
