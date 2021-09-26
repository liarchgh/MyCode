#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,t;
    scanf("%d",&n);
    int d[n+1][3];
    memset(d,0x3f,sizeof(d));
    d[0][0]=d[0][1]=d[0][2]=0;
    for(int o=1;o<=n;++o)
    {
        scanf("%d",&t);
        switch(t)
        {
            case 0:d[o][0]=min(d[o-1][0],min(d[o-1][1],d[o-1][2]))+1;
            break;
            case 1:d[o][1]=min(d[o-1][0],d[o-1][2]);
                d[o][0]=min(d[o-1][0],min(d[o-1][1],d[o-1][2]))+1;
            break;
            case 2:d[o][2]=min(d[o-1][1],d[o-1][0]);
                d[o][0]=min(d[o-1][0],min(d[o-1][1],d[o-1][2]))+1;
            break;
            case 3:
                d[o][2]=min(d[o-1][1],d[o-1][0]);
                d[o][1]=min(d[o-1][0],d[o-1][2]);
        }
    }
    int ans=min(d[n][0],min(d[n][1],d[n][2]));
    printf("%d\n",ans);
    return 0;
}
