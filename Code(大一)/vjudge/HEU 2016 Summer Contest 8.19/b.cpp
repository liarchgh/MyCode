//ֱ�������ƥ��WA�� ��֪��Ϊʲô ÿ�ÿζ�����һ�� ����1�Ͱѽ��+1 ����WA�� ����� �ĳ�ÿ�ÿζ�ֱ��pan��A��
#include <cstdio>
#include <cstring>

using namespace std;

int n,p,g[105][305],vis[305],link[305];
bool dfs(int x) {
    for(int i=1; i<=n; ++i) {
        if(g[x][i] && !vis[i]) {
            vis[i]=1;
            if(link[i]==-1 || dfs(link[i])) {
                link[i]=x;
                return 1;
                }
            }
        }
    return 0;
    }
int main() {
    int t,a,b;
    scanf("%d",&t);
    while(t--) {
        memset(g,0,sizeof(g));
        memset(link,-1,sizeof(link));
        scanf("%d%d",&p,&n);
        for(int i=0; i < p; ++i) {
            scanf("%d",&a);
            for(int j=0; j < a; ++j) {
                scanf("%d",&b);
                g[i][b]=1;
                }
            }
        int pan=1;
        for(int i=0; i<p; ++i) {
            memset(vis,0,sizeof(vis));
            if(pan && !dfs(i)) {
                pan=0;
                }
            }
        if(pan) {
            printf("YES\n");
            }
        else printf("NO\n");
        }
    return 0;
    }
