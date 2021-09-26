//第一次试着用了文件输入 确实方便 而且文件也可以使用 还不错 一道二分图匹配的题 不难 就是才开始需要将所有点分为两个集合 并判断能不能分成功
#include <cstdio>
#include <fstream>
#include <cstring>
#include <queue>

using namespace std;

int n,m,g[205][205],vis[205],link[205],biao[205];
bool dfs(int x) {
    //if(vis[x])return false;
    vis[x] = 1;
    for (int i = 1; i <= n; ++i) {
        if (g[x][i] && !vis[i]) {
            vis[i] = 1;
            if (link[i] == -1 || dfs(link[i])) {
                link[i] = x;
                return true;
            }
        }
    }
    return false;
}
int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("in.txt","r",stdin);
// #endif
    int a,b,p;
    while (scanf("%d", &n) != EOF) {
        memset(g,0,sizeof(g));
        memset(biao, 0, sizeof(biao));
        p=1;
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            g[a][b] = g[b][a] = 1;
        }
        queue<int>q;
        for (int i = 1; i <= n; ++i) {
            if (!biao[i]) {
                biao[i] = 1;
                q.push(i);
                while (!q.empty()) {
                    int x=q.front();
                    q.pop();
                    for (int ii = 1; ii <= n; ++ii) {
                        if (g[x][ii]) {
                            if (biao[ii]) {
                                if (biao[ii] + biao[x] == 3) {
                                    continue;
                                }
                                else {
                                    p=0;
                                    break;
                                }
                            }
                            else {
                                biao[ii] = 3-biao[x];
                                q.push(ii);
                            }
                        }
                    }
                    if (!p) break;
                }
            }
            if (!p) {
                break;
            }
        }
        if (!p) {
            printf("No\n");
            continue;
        }
        else {
            int ans = 0;
            memset(link, -1, sizeof(link));
            for (int j = 1; j <= n; ++j) {
                if (biao[j] == 2) continue;
                memset(vis, 0, sizeof(vis));
                if (dfs(j)) {
                    ++ans;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
