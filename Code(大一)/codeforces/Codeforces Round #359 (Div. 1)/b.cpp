//#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
#define Riep(n) for(int i=1;i<=n;i++)
#define Riop(n) for(int i=0;i<n;i++)
#define Rjep(n) for(int j=1;j<=n;j++)
#define Rjop(n) for(int j=0;j<n;j++)
#define mst(ss,b) memset(ss,b,sizeof(ss));
typedef long long LL;
template<class T> void read(T&num) {
    char CH; bool F=false;
    for(CH=getchar();CH<'0'||CH>'9';F= CH=='-',CH=getchar());
    for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());
    F && (num=-num);
}
int stk[70], tp;
template<class T> inline void print(T p) {
    if(!p) { puts("0"); return; }
    while(p) stk[++ tp] = p%10, p/=10;
    while(tp) putchar(stk[tp--] + '0');
    putchar('\n');
}

const LL mod=1e9+7;
const double PI=acos(-1.0);
const LL inf=1e18;
const int N=3e5+10;
const int maxn=1005;

int n,q,son[N],ans[N],root[N];
vector<int>ve[N];
void dfs(int x,int fa)
{
    int len=ve[x].size(),mmax=0,pos=x;
    son[x]=1;
    ans[x]=x;
    for(int i=0;i<len;i++)
    {
        int y=ve[x][i];
        if(y==fa)continue;
        dfs(y,x);
        son[x]+=son[y];
        if(son[y]>mmax)
        {
            mmax=son[y];
            pos=y;
        }
    }
    ans[x]=ans[pos];
    while(ans[x]!=x&&son[x]>2*son[ans[x]])
        ans[x]=root[ans[x]];
}
int main()
{
    read(n);read(q);
    int x;
    for(int i=2;i<=n;i++)
    {
        read(x);
        root[i]=x;
        ve[x].push_back(i);
        ve[i].push_back(x);
    }
    dfs(1,-1);
    while(q--)
    {
        read(x);
        printf("%d\n",ans[x]);
    }
        return 0;
}
