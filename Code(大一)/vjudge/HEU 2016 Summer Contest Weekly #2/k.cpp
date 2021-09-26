#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

pair<int,int>a[200005];
int main()
{   int n;
    scanf("%d",&n); getchar();
    for(int i=0; i<n; ++i)
    {   switch(getchar())
        {   case 'L':a[i].first=-1; break;
            case 'R':a[i].first=1; }
            }
    for(int i=0; i<n; ++i)
    {   scanf("%d",&a[i].second); ++a[i].second;}
    //printf("111111\n");
    int ans=1000000005,num=0,l;
    l=a[0].first*a[0].second;
    for(int i=0;i<n;++i)
    {
        if(a[i].first<0)
        {
            if(l<0)
                l=-a[i].second;
            else
            {
                ++num;
                ans=min(a[i].second-l,ans);
                l=-a[i].second;
            }
        }
        if(a[i].first>0) l=a[i].second;
    }
    if(!num)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n",ans/2);
    return 0; }
