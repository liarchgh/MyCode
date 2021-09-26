#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int d[1005][1005],ch[1005][1005]={0},l0,l1,ans=0;
int fin(int x,int y);
char s[2][1005];
int main()
{
    memset(d,-1,sizeof(d));
    scanf("%d",&l0);getchar();
    gets(s[0]);
    scanf("%d",&l1);getchar();
    gets(s[1]);
    int a=fin(l0-1,l1-1),m=l0>l1?l0:l1;
    printf("%d %d\n",ch[l0-1][l1-1],a);
    return 0;
}
int fin(int x,int y)
{//printf("%d %d\n",x,y);
    if(x<0 || y<0) return 0;
    if(d[x][y]!=-1) return d[x][y];
    int a=fin(x-1,y);
    a=max(a,fin(x,y-1));
    if(s[0][x]==s[1][y])
        {a=max(a,fin(x-1,y-1)+1);
        ch[x][y]=ch[x-1][y-1]+1;
        }
    else ch[x][y]=ch[x-1][y-1]+2;
    d[x][y]=a;
    //if(s[0][x]==s[1][y] &&x>0 && y>0) ans+=d[x][y]-d[x-1][y-1];
    return a;
}
/*
10 AGTCTGACGC
11 AGTACGTAGGC
*/
//10 AGT  C  TGACGC
//11 AGTACGT  AGGC
