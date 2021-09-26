#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int l,r,c,s[3],e[3],w[33][33][33],d[33][33][33],ans,
f[6][3]= {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct note
{
    int l,r,c;

    note(int x,int y,int z)
    {
        l=x;
        r=y;
        c=z;
    }
};
queue<note>q;
int main()
{
    while(scanf("%d%d%d",&l,&r,&c),l||r||c)
    {
        ans=0;
        memset(d,0,sizeof(d));
        getchar();
        for(int i=0; i<l; ++i)
        {
            for(int j=0; j<r; ++j)
            {
                for(int k=0; k<c; ++k)
                {
                    switch(getchar())
                    {
                    case 'S':
                        d[i][j][k]=1;
                        s[0]=i;
                        s[1]=j;
                        s[2]=k;
                        break;
                    case 'E':
                        e[0]=i;
                        e[1]=j;
                        e[2]=k;
                        break;
                    case '.':
                        w[i][j][k]=1;
                        break;
                    case '#':
                        w[i][j][k]=0;
                        break;
                    }
                }
                getchar();
            }
            getchar();
        }
        note o(s[0],s[1],s[2]);
        d[o.l][o.r][o.c]=1;
        q.push(o);
        while(!q.empty())
        {
            note x=q.front();
            q.pop();
            for(int i=0; i<6; ++i)
            {
                note z=x;
                z.l+=f[i][0];
                z.r+=f[i][1];
                z.c+=f[i][2];
                if(z.l==e[0] && z.r==e[1] && z.c==e[2]) ans=d[x.l][x.r][x.c]+1;
                else if(z.l>=0 && z.l<l && z.r>=0 && z.r<r && z.c>=0 && z.c<c && !d[z.l][z.r][z.c] &&w[z.l][z.r][z.c])
                {
                    d[z.l][z.r][z.c]=d[x.l][x.r][x.c]+1;
                    q.push(z);
                }
            }
        }
        /*
        for(int i=0; i<l; ++i)
        {
            for(int j=0; j<r; ++j)
            {
                for(int k=0; k<c; ++k)
                {
                    printf("%d ",d[i][j][k]);
                }
                putchar('\n');
            }
            putchar('\n');
        }
        */
        if(ans)
            printf("Escaped in %d minute(s).\n",ans-1);
        else printf("Trapped!\n");
    }
    return 0;
}
