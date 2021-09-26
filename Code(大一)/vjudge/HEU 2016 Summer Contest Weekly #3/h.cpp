#include <cstdio>
#include <cstring>

int tu[255][255],lian[255][255],
zou[4][2]={{1,1},{1,-1},{-1,1},{-1,-1}},
T,n,m,q,x1,y1,vis[255][255],
bafang[8][2]={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0}};
bool zhao(int x,int y){
    if(x==n-1) return true;
    int x1,y1;
    for(int i=0;i<4;++i){
        x1=x+zou[i][0];y1=y+zou[i][1];
        if(x1>=0 && x1<n && y1>=0 && y1<m&& !vis[x1][y1] && tu[x1][y1]){
            vis[x1][y1]=1;
            if(zhao(x1,y1)) return true;
        }
    }
    return false;
}
bool dfs(){
    memset(vis,0,sizeof vis);
    for(int i=0;i<m;++i){
        if(tu[0][i]){
            vis[0][i]=1;
            if(zhao(0,i)) return true;
        }
    }
    return false;
}
int fin(int x,int y){//连到左边 返回1 右边返回 2 独立返回3
    if(y==0){
        lian[x][y]=1;
        return 1;
    }
    if(y==m-1){
        lian[x][y]=2;
        return 2;
    }
    if(lian[x][y]) return lian[x][y];
}
bool cha(int x,int y){
    int p=0,x1,y1;
    lian[x][y]=3;
    for(int i=0;i<8;++i){
        x1=x+bafang[i][0];
        y1=y+bafang[i][1];
        if(x1<0 || x1>=n || y1<0 || y1>=m || vis[x1][y1]) continue;
        if(!tu[x1][y1]){
            int a=fin(x1,y1);
            vis[x1][y1]=1;
            if(a!=3){
                if(lian[x][y]==3) lian[x][y]=a;
                else if(lian[x][y]+a==3) return true;
            }
        }
    }
    for(int i=0;i<8;++i){
        x1=x+bafang[i][0];
        y1=y+bafang[i][1];
        if(x1<0 || x1>=n || y1<0 || y1>=m) continue;
        lian[x1][y1]=lian[x][y];
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(lian,0,sizeof(lian));
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=0;i<n;++i){
            for(int ii=0;ii<m;++ii){
                tu[i][ii]=!(getchar()-'0');
                //if(!tu[i][ii]) cha(i,ii);
            }
            getchar();
        }
        scanf("%d",&q);
        int ans=-1;
        if(!dfs()) ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=q;++i){
            scanf("%d%d",&x1,&y1);
            tu[x1][y1]=0;
            vis[x1][y1]=1;
            if(ans<0 && cha(x1,y1)) ans=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
