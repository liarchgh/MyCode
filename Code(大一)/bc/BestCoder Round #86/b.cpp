#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>

using namespace std;

int t,n,a[100005],cha[100005],xa,dier,diyi;
pair<int,int>yuanlai[100005];
int qu(int x);
int main()
{   long long ans;
    scanf("%d",&t);
    while(t--)
    {   memset(cha,-1,sizeof(cha));
        ans=0;
        diyi=dier=-1;
        scanf("%d",&n);
        for(int i=0; i<n; ++i) scanf("%d",&a[i]);
        for(int i=0; i<n-1; ++i)
        {   int x=a[i]-a[i+1];
            if(x<0) x=-x;
            if(x>diyi)
            {   dier=diyi;
                diyi=x;
                xa=i; }
            else if(dier<x) dier=x;
            yuanlai[i].first=x;
            yuanlai[i].second=i; }
        sort(yuanlai,yuanlai+n-1);
        if(xa!=0)
        {   cha[0]=qu(0);
            int x=a[xa+1]-a[xa-1],dier=qu(xa);
            if(x<0) x=-x;
            cha[xa]=dier>x?dier:x;
            ans+=cha[0]; }
        else cha[xa]=dier;
        if(xa!=n-2)
        {   cha[n-1]=qu(n-1);
            int x=a[xa+2]-a[xa],dier=qu(xa+1);
            if(x<0) x=-x;
            cha[xa+1]=dier>x?dier:x;
            ans+=cha[n-1]; }
        else cha[xa+1]=dier;
        ans+=cha[xa]+cha[xa+1];
        for(int i=1; i<n-1; ++i)
        {   if(i==xa || i==xa+1) continue;
            int x=a[i+1]-a[i-1],diyi=qu(i);
            if(x<0) x=-x;
            cha[i]=diyi>x?diyi:x;
            ans+=cha[i]; }
        printf("%I64d\n",ans); }
    return 0; }

int qu(int x)
{   for(int i=n-2; i>=0; --i)
    {   if(yuanlai[i].second!=x &&yuanlai[i].second!=x-1)
            return yuanlai[i].first; }
    return 0; }
