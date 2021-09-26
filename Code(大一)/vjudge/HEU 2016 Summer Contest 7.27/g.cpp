#include<cstdio>
#include<queue>
#include<cstring>
#include<utility>

using namespace std;

int n,m,d[105][105],c[105][105],ans,
f[8][2]= {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
queue<pair<int,int> >q;
int sou(int y,int x);
int main()
{
    while(scanf("%d %d",&n,&m),n)
    {
        ans=0;
        memset(d,0,sizeof(d));
        getchar();
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                switch(getchar())
                {
                case '*':
                    c[i][j]=0;
                    break;
                case '@':
                    c[i][j]=1;
                    break;
                }
            }
            getchar();
        }

/*
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                printf("%d ",c[i][j]);
            }
            putchar('\n');
        }
*/

        d[0][0]=1;
        if(c[0][0])
        {
            ++ans;
            sou(0,0);
        }
        q.push(make_pair(0,0));
        while(!q.empty())
        {
            int y=q.front().first,x=q.front().second,a,b;
            q.pop();
            for(int i=0; i<8; ++i)
            {
                a=y+f[i][0];
                b=x+f[i][1];
                if(a<0 || b<0 || a>=n || b>=m) continue;
                if(!d[a][b])
                {
                    d[a][b]=1;
                    q.push(make_pair(a,b));
                    if(c[a][b])
                    {
                        ++ans;
                        d[a][b]=1;
                        sou(a,b);
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

int sou(int y,int x)
{
    int a,b;
    for(int i=0; i<8; ++i)
    {
        a=y+f[i][0];
        b=x+f[i][1];
        if(a<0 || b<0 || a>=n || b>=m) continue;
        if(!d[a][b])
        {
            d[a][b]=1;
            if(c[a][b])
                sou(a,b);
            else q.push(make_pair(a,b));
        }
    }
}
/*
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
*/
