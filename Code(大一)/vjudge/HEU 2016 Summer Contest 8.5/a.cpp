//ctrl+c
#include <iostream>
#include <cstdio>
#include <cstring>
#define mem(a,b) memset(a,b,sizeof(a))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int maxn=200+30;
int inf=0x3f3f3f3f;
char Map[maxn][110];
int f[maxn][maxn],g[maxn][maxn],head[maxn],e[maxn],next[maxn],vis1[maxn],vis2[maxn];
int cost[maxn],qn[maxn];
int n,m,tot,qe;
int getL(char *s)
{   int i;
    for(i=0; i<tot; i++)
        if(strcmp(s,Map[i])==0) return i;
    strcpy(Map[tot++],s);
    return tot-1; }
void dp(int u)
{   int i,j,k,v,p;
    if(!vis2[u])
    {   f[u][0]=0;
        f[u][1]=cost[u];
        qn[u]=1;
        return; }
    qn[u]=0;
    f[u][0]=0;
    for(i=head[u]; i!=-1; i=next[i])
    {   dp(e[i]);
        qn[u]+=qn[e[i]]; }
    qn[u]++;
    mem(g,inf);
    g[0][0]=0;
    int sum=0;
    for(i=head[u],j=1; i!=-1; i=next[i],j++) //01背包的思路
    {   v=e[i];
        sum+=qn[v];
        for(k=0; k<=sum; k++)
        {   for(p=0; p<=qn[v]; p++)
            {   g[j][k]=min(g[j-1][k-p]+f[v][p],g[j][k]); } } }
    for(i=1; i<=sum; i++)
        f[u][i]=g[j-1][i];
    f[u][qn[u]]=cost[u]; }
int main()
{   char s[101];
    while(gets(s))
    {   if(s[0]=='#') break;
        sscanf(s,"%d %d",&n,&m);
        tot=0; qe=0;
        int i,loc,am,j,u,v;
        mem(f,inf);
        mem(head,-1);
        mem(vis1,0); mem(vis2,0);
        for(i=0; i<n; i++)
        {   scanf("%s %d",s,&am);
            u=getL(s);
            cost[u]=am;
            while(scanf("%c",s)&&s[0]!='\n')
            {   vis2[u]=1;
                scanf("%s",s);
                v=getL(s);
                vis1[v]=1;
                next[qe]=head[u];
                head[u]=qe;
                e[qe++]=v; } }
        for(i=0; i<n; i++)
        {   if(!vis1[i])
            {   next[qe]=head[n];
                head[n]=qe;
                e[qe++]=i; } }
        vis2[n]=1;
        cost[n]=inf;
        dp(n);
        int ans=inf;
        for(i=m; i<=(qn[n]-1); i++) ans=min(ans,f[n][i]);
        printf("%d\n",ans); }
    return 0; }
