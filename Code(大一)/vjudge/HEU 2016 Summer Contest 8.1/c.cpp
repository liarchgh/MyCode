#include<cstdio>

long long pow(long long x);//返回2的x次方%mod
const long long mod=1000000007;
int main()
{
    long long n;
    scanf("%I64d",&n);
    if(n==1)
    {
        printf("3\n");return 0;
    }
    if(!n)
    {
        printf("1\n");return 0;
    }
    long long an=pow(n-1);
    printf("%I64d\n",(an*2+1)%mod*an%mod);
    return 0;
}

long long pow(long long x)
{
    long long a=2,b=1;
    while(x)
    {
        if(x&1)
        {
            b=b*a%mod;
        }
        a=a*a%mod;
        x>>=1;
    }
    return b;
}

/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <iomanip>
#include <set>
#include <vector>
#include <cstdio>
#include <stack>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll pow3(ll a,ll b)
{
    ll r=1,base=a;
    while(b)
    {
        if(b&1)
            r=r*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return r;
}
int main()
{
    ll n;
    cin>>n;
    ll last=pow3(2,n);
    //cout<<last<<endl;
    ll res=(1+last)*last/2;
    cout<<res%mod<<endl;
    return 0;
}
*/
