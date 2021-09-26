#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1],d[n+1];
    memset(d,-1,sizeof(d));
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&a[i]);
        //printf("%d %d\n",a[i],d[i]);
    }
    d[1]=0;
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int now=q.front();
        //printf("%d\n",now);
        q.pop();
        for(int x=now-1; x<=now+1; x+=2)
        {
            if(x>=1&&x<=n)
            {
                if(d[x]==-1 || d[x]>d[now]+1)
                {
                    d[x]=d[now]+1;
                    q.push(x);
                    //printf("%d %d\n",x,d[x]);
                }
            }
        }

        if(d[a[now]]>d[now]+1 || d[a[now]]==-1)
        {
            d[a[now]]=d[now]+1;
            q.push(a[now]);
            //printf("%d %d\n",a[now],d[a[now]]);
        }

    }
    for(int i=1; i<n; ++i)
        printf("%d ",d[i]);
    printf("%d\n",d[n]);
    return 0;
}
