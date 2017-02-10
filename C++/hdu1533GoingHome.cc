//不难 也是一道直接套模板的题目 直接过了 才开始没想到变为负边权 直接用了求最大值的模板 有点傻 变了之后直接一次过了 就是自己敲的时候细节之处太多了 其他还好
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int mx = 105, inf = 0xfffffff;
int n, m, cost[mx][mx], visx[mx], visy[mx], linky[mx], slack[mx], lx[mx], ly[mx];
struct no
{
    int x, y;
    no(int a, int b)
    {
        x = a;
        y = b;
    }
    int operator-(no an)
    {
        return abs(an.x - x) + abs(an.y - y);
    }
};

vector<no>house, man;

int find_zgl(int x) {
    visx[x] = 1;
    for (int y = 0; y < house.size(); ++y) {
        if (visy[y]) continue;
        int t = lx[x] + ly[y] - cost[x][y];
        if (!t) {
            visy[y] = 1;
            if (linky[y] == -1 || find_zgl(linky[y])) {
                linky[y] = x;
                return 1;
            }
        }
        else {
            slack[y] = min(slack[y], t);
        }
    }
    return 0;
}

int KM()
{
    memset(linky, -1, sizeof(linky));
    memset(ly, 0, sizeof(ly));
    for (int i = 0; i < house.size(); ++i)
    {
        lx[i] = -inf;
        for (int j = 0; j < house.size(); ++j)
            lx[i] = max(cost[i][j], lx[i]);
    }
    for (int x = 0; x < house.size(); ++x)
    {
        for (int i = 0; i < house.size(); ++i)
            slack[i] = inf;
        while (1)
        {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if (find_zgl(x))
            {
                break;
                // printf("----1\n");
            }
            int d = inf;
            for (int i = 0; i < house.size(); ++i)
                if(!visy[i]) d = min(d, slack[i]);
            // if(d) cout << d << endl;
            for (int i = 0; i < house.size(); ++i)
            {
                if (visx[i]) lx[i] -= d;
                if (visy[i]) ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < house.size(); ++i) {
        if (linky[i] > -1) res += cost[linky[i]][i];
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D://in.ls", "r", stdin);
    freopen("D://out.ls", "w", stdout);
#endif
    while (scanf("%d%d", &n, &m), n || m)
    {
        // cout << n << m << endl;
        house.clear();
        man.clear();
        getchar();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // cout << i << ' ' << j << endl;
                switch (getchar())
                {
                case 'H':
                    house.push_back(no(i, j));
                    // printf("-----%d %d\n", i, j);
                    break;
                case 'm':
                    // printf("+++++%d %d\n", i, j);
                    man.push_back(no(i, j));
                }
            }
            getchar();
        }
        // printf("-------%d %d\n", house.size(), man.size());
        for (int i = 0; i < man.size(); ++i)
        {
            for (int j = 0; j < house.size(); ++j)
            {
                cost[i][j] = -(man[i] - house[j]);
            }
        }
        printf("%d\n", -KM());
    }
    return 0;
}
