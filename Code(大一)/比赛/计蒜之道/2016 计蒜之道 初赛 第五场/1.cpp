#include<cmath>
#include<cstdio>
using namespace std;
double a[25];
int main()
{
    int k,n;
    double l,ans=0;
    scanf("%d%d%lf",&n,&k,&l);
    for(int i=0;i<k;++i)
        {ans+=l*((double)n-1/2.0);
        l=l*sin(M_PI*(1/2.0-1.0/n));
        }
        ans+=l*(n-1);
        printf("%lf",ans);
    return 0;
}
