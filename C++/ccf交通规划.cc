//http://115.28.138.223/view.page?gpid=T44
//还没过 再想想
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

const int mx = 10000+5, inf = 0xfffffff;
int n, m, fa[mx], min_len[mx], mark[mx];
struct ed
{
    int nod, len;
    ed(int a, int b)
    {
        nod = a;
        len = b;
    }
};
vector<ed>near[mx];

int find_min()
{
    int x = -1;
    for(int i = 1; i <= n; ++i)
    {
        if(!mark[i] && (x < 0 || min_len[i] < min_len[x])) x = i;
    }
    return x;
}

void chu(int x)
{
    mark[x] = 1;
    for(vector<ed>::iterator it = near[x].begin(); it != near[x].end(); ++it)
    {
        if(min_len[it->nod] > min_len[x] + it->len)
        {
            min_len[it->nod] = min_len[x] + it->len;
            fa[it->nod] = x;
        }
        else if(min_len[it->nod] == min_len[x] + it->len && min_len[it->nod] - min_len[fa[it->nod]] > it->len)
        {
            min_len[it->nod] = min_len[x] + it->len;
            fa[it->nod] = x;
        }
    }
}

int dfs()
{
    int sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        sum += min_len[i] - min_len[fa[i]];
        //printf("%d\n", min_len[i]);
    }
    return sum;
}

int main()
{
    //freopen("in.cc", "r", stdin);
    //freopen("out.cc", "w", stdout);
    scanf("%d%d", &n, &m);
    int a, b, c;
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        near[a].push_back(ed(b, c));
        near[b].push_back(ed(a, c));
        //printf("%d\n", near[0][0].len);
    }
    min_len[1] = 0;
    memset(mark, 0, sizeof(mark));
    memset(fa, 0, sizeof(fa));
    for(int i = 2; i <= n; ++i)
    {
        min_len[i] = inf;
    }
    for(int i = 1; i < n; ++i)
    {
        int x = find_min();
        if(x < 0) break;
        chu(x);
    }
    printf("%d\n", dfs());
    return 0;
}
