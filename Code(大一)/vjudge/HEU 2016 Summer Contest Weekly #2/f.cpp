#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

pair<int,int>a[105];
int main()
{
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&t);
        a[i].first=t;
        a[i].second=i+1;
    }
    sort(a,a+n);
    for(int i=0;i<n/2;++i)
    {
        printf("%d %d\n",a[i].second,a[n-1-i].second);
    }
    return 0;
}
