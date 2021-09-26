#include<cstdio>

long long exgcd(long long a,long long b,long long &x,long long &y);
int main()
{
    long long int x,y,m,n,l;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    if(x>l) x%=l;if(y>l) y%=l;
    if(x<y)
    {
        int t=x;x=y;y=t;
        t=m;m=n;n=t;
    }
    long long ans=0,z;
    long long gcd=exgcd(n-m,l,ans,z),r=l/gcd;
    if(r<0) r=-r;
    if((x-y)%gcd) printf("Impossible\n");
    else
    {
        printf("%lld\n",((x-y)/gcd*ans%r+r)%r);
    }
    return 0;
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    else
    {
        long long temp=exgcd(b,a%b,x,y);
        long long t = x;
    x = y;
    y = t - (a / b) * y;
        return temp;
    }
}
/*
#include<cstdio>
#include<set>

using namespace std;

set<int>d;
int main()
{
    long long int x,y,m,n,l,dist,ra,rb,v;
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
    ra= m%l;rb=n%l;v=rb-ra;
    dist=((x%l+l)%l-(y%l+l)%l+l)%l;
    if(v<0){v=-v;dist=l-dist;}
    v%=l/2;
    if(!v)
    {
        printf("Impossible\n");
        return 0;
    }
    long long ans=0,ls=l*v+dist;
    if(ls%v)
    {
        printf("Impossible\n");
        return 0;
    }
    long long ll=0,lr=v,mid=(ll+lr)/2;
    ls=dist+l*mid;
    while(ll!=lr)
    {
        //printf("%lld %lld\n",ls,v);
        if(!(ls%v))
        {
            lr=mid;mid=(ll+lr)/2;
            ls=dist+l*mid;
        }
        else
        {
            ll=mid+1;mid=(ll+lr)/2;
            ls=dist+l*mid;
        }
    }
    printf("%lld\n",ls/v);
    return 0;
}
*/
