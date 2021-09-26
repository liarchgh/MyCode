#include<cstdio>
#include<queue>

using namespace std;

const unsigned long long mx=10000000000000000000;
int pan(unsigned long long int x);
unsigned long long n,ans;
int main()
{
    while(scanf("%lld",&n),n)
    {
        ans=0;
        pan(1);
        printf("%lld\n",ans);
    }
    return 0;
}

int pan(unsigned long long int x)
{
    if(x>=mx) return 0;
    if(ans) return 1;
    if(!(x%n)) {ans=x;return 1;}
    if(pan(x*10)) return 1;
    if(pan(x*10+1))return 1;
    return 0;
}
