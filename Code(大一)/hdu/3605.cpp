//没过 等明天看了网络流再来看吧
#include <cstido>
#include <fstream>

using namespace std;

int n,m;
int main() {
    int a;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a);
            }
        }
    }
    return 0;
}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define INF 1e9

using namespace std;

const int maxn =1200;

struct Edge {
    int from,to,cap,flow;
    Edge(int f,int t,int c,int fl):from(f),to(t),cap(c),flow(fl) {}};

struct Dinic {
    int n,m,s,t;

    vector<Edge> edges;

    vector<int> G[maxn];

    int d[maxn];

    int cur[maxn];


    bool vis[maxn];
    void init(int n,int s,int t)    {
        this->n=n, this->s=s, this->t=t;
        edges.clear();
        for (int i=0;i<n;++i) G[i].clear();
    }    void AddEdge(int from,int to,int cap)    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }    bool BFS()    {
        queue<int> Q;
        memset(vis,0,sizeof(vis));
        Q.push(s);
        d[s]=0;
        vis[s]=true;
        while (!Q.empty())        {
            int x=Q.front();
            Q.pop();
            for (int i=0;i<G[x].size();++i)            {
                Edge &e=edges[G[x][i]];
                if (!vis[e.to] && e.cap>e.flow)                {
                    vis[e.to]=true;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }        return vis[t];
    }    int DFS(int x,int a)    {
        if (x==t || a==0) return a;
        int flow=0,f;
        for (int &i=cur[x];i<G[x].size();++i)        {
            Edge &e=edges[G[x][i]];
            if (d[e.to]==d[x]+1 && (f=DFS(e.to,min(a,e.cap-e.flow) ) )>0)            {
                e.flow +=f;
                edges[G[x][i]^1].flow -=f;
                flow +=f;
                a -=f;
                if (a==0) break;
            }
        }        return flow;
    }    int max_flow()    {
        int ans=0;
        while (BFS())        {
            memset(cur,0,sizeof(cur));
            ans += DFS(s,INF);
        }        return ans;
    }
}DC;
int n,m;
int num[maxn];

//num[i]=x表示选择方案为i(二进制形式)的人一共有x人int can[10+5];

//星球最多容纳的人数


int main() {
    while (scanf("%d%d",&n,&m)==2)    {
        memset(num,0,sizeof(num));
        for (int i=1;i<=n;i++)        {
            int id=0;
            for (int j=m-1;j>=0;--j)            {
                int v;
                scanf("%d",&v);
                if (v) id |= 1<<j;
            }            ++num[id];
        }        for (int i=0;i<m;i++) scanf("%d",&can[i]);
        int src=1024+m,dst=1025+m;
        DC.init(1026+m,src,dst);
        for (int i=0;i<1024;++i)if (num[i])        {
                DC.AddEdge(src,i,num[i]);
                for (int j=0;j<m;++j)if (i&(1<<j))                DC.AddEdge(i,1024+j,INF);
            }        for (int i=0;i<m;++i)if (can[i])            DC.AddEdge(1024+i,dst,can[i]);
        printf("%s\n",DC.max_flow()==n?"YES":"NO");
    }    return 0;
}