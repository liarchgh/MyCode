#include<cstdio>
using namespace std;

const int INF=200005;
int n,pre[INF],cur[INF],thread=0,ans=0;//pre存这一点的根节点 cur存父节点
int fin(int x)
{
    return pre[x]=pre[x]==x?x:fin(pre[x]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) pre[i]=i;
    for(int i=1; i<=n; ++i)
    {
        scanf("%d",&cur[i]);
        if(cur[i]==i)
        {
            if(!thread) thread = i;
            ++ans;
        }
        else
        {
            int f1=fin(i),f2=fin(cur[i]);
            if(f1==f2)
            {
                cur[i]=i;
                //if(!thread) thread=i;
                ++ans;
            }
            else
            {
                pre[f1]=f2;
            }
        }
    }
    if(!thread)
    {
        ++ans;
        for(int i=1; i<=n; ++i) if(cur[i]==i)
            {
                thread=i;
                break;
            }
    }
    printf("%d\n",ans-1);
    //printf("%d\n",thread);
    for(int i=1; i<n; ++i)
    {
        if(cur[i]==i)
            printf("%d ",thread);
        else printf("%d ",cur[i]);
    }
    int i=n;
    if(cur[i]==i)
        printf("%d\n",thread);
    else printf("%d\n",cur[i]);
    //for(int i=1; i<=n; ++i) printf("%d ",cur[i]);
    return 0;
}
