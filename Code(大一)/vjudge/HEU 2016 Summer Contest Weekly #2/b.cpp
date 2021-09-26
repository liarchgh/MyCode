#include<cstdio>
#include<algorithm>

using namespace std;

    int n,a[100005];
    long long inf=0,ans=0;
    int zhao(int start,long long int x);//在a数组中找x 起始位置start
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        inf=max(inf,(long long)a[i]);
    }
    inf<<=1;
    sort(a,a+n);
    for(int i=0;i<n;++i)
    {
    //printf("%lld\n",inf);
        long long int x=1;
        while(x<a[i]) x<<=1;
        while(x<=inf)
        {
            long long t=x-a[i];
            ans+=zhao(i+1,t);//printf("%lld\n",ans);
            x<<=1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
int zhao(int start,long long int x)//在a数组中找x
{
    if(start>=n) return 0;
    if(a[start]>x || a[n-1]<x) return 0;
    //printf("%d %d\n",start,x);
    int l=start,r=n-1;
    int mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(a[mid]<=x) l=mid+1;
        else if(a[mid]>x) {
                r=mid;
        }
    }
    int x1;
    if(a[l]==x) x1=l;
    else x1=l-1;
    l=start,r=n-1;
    while(l<r)
    {
        mid=(l+r+1)>>1;
        if(a[mid]<x) l=mid;
        else if(a[mid]>=x)
        { r=mid-1;}
    }
    int x2;
    if(a[r]==x) x2=r;
    else x2=r+1;
    return x1-x2+1;
}
