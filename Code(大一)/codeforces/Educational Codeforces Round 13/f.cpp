#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

const long long INF=0x7fffffffffffffff;
vector<pair<int,int> >q;
int main()
{
    int n,ty,a,b;
    scanf("%d",&n);
    int d[n],jilu[n],p=0;
    memset(d,0,sizeof(d));
    for(int o=1;o<=n;++o)
    {
        scanf("%d",&ty);
        switch(ty)
        {
        case 1:
            scanf("%d%d",&a,&b);
            q.push_back(make_pair(a,b));
            jilu[o]=p++;
            break;
        case 2:
            scanf("%d",&a);
            d[jilu[a]]=1;
            break;
        case 3:
            long long a,b;int c;
            scanf("%I64d",&a);
            c=1;
            b=-INF;
            for(int i=0; i<q.size(); ++i)
            {
                if(!d[i])
                {
                    b=max(b,a*q[i].first+q[i].second);
                    c=0;
                }
            }
            if(c) printf("EMPTY SET\n");
            else
            {
                printf("%I64d\n",b);
            }
            break;
        }
    }
    return 0;
}
