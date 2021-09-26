#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200000+5;
int a[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n,m,k;
        scanf("%I64d%I64d%I64d",&n,&m,&k);
        for(int i=1; i<=n; i++) scanf("%I64d",&a[i]);
        long long l=1,r=1;
        long long s=0;
        long long ans=0;
        while(l<=n)
        {
            while(r<=n&&s<k)
            {
                if(a[r]>=m) s++;
                r++;
            }
            if(s>=k) ans+=(n-r+2);
            if(a[l]>=m) s--;
            l++;
        }
        printf("%I64d\n",ans);
    }
}
