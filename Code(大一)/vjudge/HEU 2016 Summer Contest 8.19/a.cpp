//��Ĳ�̫����Ⱑ �������㷨
#include <cstdio>
#include <cstring>

using namespace std;

const int mx=105;
int n,m,k,g[mx][mx],vis[mx],link[mx];

int dfs(int x){
    for(int i=1;i<m;++i){//���α����ұߵĵ�
        if(g[x][i] && !vis[i]){
            vis[i]=1;//�Ժ�Ͳ������������ ��Ϊ����һ���Ѿ��Ҳ���������·��
            if(link[i]==-1 || dfs(link[i])){//����ұߵ���������ӵ��е� ��һ���ܲ�������һͷ�ҵ�һ������չ�ĵ� ����һ��������·
                link[i]=x;//����ұߵĵ����ϴ���������ߵĵ�
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int a,b,c;
    while(scanf("%d",&n),n){
        memset(g,0,sizeof(g));
        memset(link,-1,sizeof(link));
        scanf("%d%d",&m,&k);
        for(int i=0;i<k;++i){
            scanf("%d%d%d",&a,&b,&c);
            g[b][c]=1;
        }
        int ans=0;
        for(int i=1;i<n;++i){
            memset(vis,0,sizeof(vis));
            if(dfs(i)){
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
