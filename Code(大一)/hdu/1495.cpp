#include<cstdio>
#include<utility>
#include<cstring>
#include<queue>

using namespace std;

struct note
{
    int a[3];
    note(int x,int y,int z)
    {
        a[0]=x;
        a[1]=y;
        a[2]=z;
    }
};
int s,m,n,d[105][105][105],v[3];
queue<note>q;
int main()
{
    while(scanf("%d%d%d",&v[0],&v[1],&v[2]),v[0]||v[1]||v[2])
    {
        if(v[0]%2){
            printf("NO\n");
            continue;
        }
        int p=0;
        memset(d,0,sizeof(d));
        d[v[0]][0][0]=1;
        note a(v[0],0,0);
        q.push(a);
        while(!q.empty())
        {
            note x1=q.front();
            //printf("%d %d %d %d\n",x1.a[0],x1.a[1],x1.a[2],d[x1.a[0]][x1.a[1]][x1.a[2]]);
            q.pop();
            note x=x1;
            for(int i=0; i<3; ++i)
            {
                if(x.a[i])
                {
                    for(int k=1; k<3; ++k)
                    {
                        int j=i+k;
                        j%=3;
                        if(x1.a[i]==v[0]/2 &&x1.a[j]==v[0]/2){
                            printf("%d\n",d[x1.a[0]][x1.a[1]][x1.a[2]]-1);
                            while(!q.empty()) q.pop();
                            p=1;
                            break;
                        }
                        if(v[j]==x.a[j]) continue;
                        if(x.a[i]<=v[j]-x.a[j])
                        {
                            x.a[j]+=x.a[i];
                            x.a[i]=0;
                            if(!d[x.a[0]][x.a[1]][x.a[2]])
                            {
                                d[x.a[0]][x.a[1]][x.a[2]]=d[x1.a[0]][x1.a[1]][x1.a[2]]+1;
                                q.push(x);
                            }
                        }
                        else
                        {
                            x.a[i]-=v[j]-x.a[j];
                            x.a[j]=v[j];
                            if(!d[x.a[0]][x.a[1]][x.a[2]])
                            {
                                d[x.a[0]][x.a[1]][x.a[2]]=d[x1.a[0]][x1.a[1]][x1.a[2]]+1;
                                q.push(x);
                            }
                        }
                        x=x1;
                    }
                    if(p) break;
                }
                if(p) break;
            }
        }
        if(p) continue;
        printf("NO\n");
    }
    return 0;
}
