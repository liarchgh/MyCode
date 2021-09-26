#include<cstdio>
#include<utility>
using namespace std;

pair<__int64,__int64> huajian(pair<__int64,__int64>a);
__int64 gcd(__int64 a,__int64 b);
pair<__int64,__int64> jian(pair<__int64,__int64>a,pair<__int64,__int64>b);
__int64 a1=0,a2=0;
int main()
{
    int p=0,n,t;
    scanf("%d",&t);
    while(t--)
    {
        a1=a2=0;
        scanf("%d",&n);
        int ji[n];
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&ji[i]);
            if(ji[i]<0) ji[i]=-ji[i];
            a1+=(ji[i])*(ji[i]);
            a2+=(ji[i]);
        }
        pair<__int64,__int64>ans=huajian(make_pair(a2*a2,n));
        ans=jian(make_pair(a1,1),ans);
        printf("%I64d/%I64d\n",ans.first,ans.second);
        p=0;
    }
    return 0;
}

pair<__int64,__int64> huajian(pair<__int64,__int64>a)
{
    int g=gcd(a.first,a.second);
    return make_pair(a.first/g,a.second/g);
}

__int64 gcd(__int64 a,__int64 b)
{
    if(!a) return b;
    return gcd(b%a,a);
}

pair<__int64,__int64> jian(pair<__int64,__int64>a,pair<__int64,__int64>b)
{
    return huajian(make_pair(a.first*b.second-a.second*b.first,a.second*b.second));
}
