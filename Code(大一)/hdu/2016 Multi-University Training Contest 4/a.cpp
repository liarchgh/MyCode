//TLE


#include<cstdio>
#include<cstring>


const int inf=100005,mod=1000000007;
char a[inf],b[inf],d[inf];
long long ans(int x);
int bi(int x);//第x位开始的l位若是b 则返回1 否则返回0
int l,last;
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int v=1; v<=t; ++v)
    {
        last=-1;
        memset(d,-1,sizeof(d));
        printf("Case #%d: ",v);
        gets(a);
        gets(b);
        l=strlen(b);
        for(int i=0; i<strlen(a); ++i)
        {
            if(bi(i) && i>last) last=i;
        }
        if(-1==last)
        {
            printf("1\n");
            continue;
        }
        d[0]=0;
        printf("%lld\n",ans(0));
        for(int i=0; i<strlen(a); ++i) printf("%d %d\n",i,d[i]);
    }
    return 0;
}

long long ans(int c)
{
    int x=c;
    //printf("%d\n",x);
    long long sum=0;
    if(strlen(a)-x<l) return 0;
    while(x<strlen(a) && !bi(x))
    {
        ++x;
    }
    if(x==strlen(a))return 0;
    if(d[x]!=-1 && x!=c) return d[x];
    if(x+l<strlen(a))
        if(d[x+l]==-1)
        {
            d[x+l]=0;
            d[x+l]=ans(x+l);
            sum+=d[x+l]*2;
        }
        else sum=d[x+l]*2;
    if(last-x<l) sum=2;
    sum%=mod;
    for(int i=x+1; i<x+l; ++i)
    {
        if(bi(i))
            if(d[i]!=-1) sum+=d[i]-1;
            else
            {
                d[i]=1;
                d[i]=ans(i);
                if(i+l>last-l) sum+=1;
                else sum+=d[i+l];
            }
        sum%=mod;
    }
    d[x]=mod;
    return sum;
}

int bi(int x)
{
    if(x>strlen(a)-l) return 0;
    char a1[l+1];
    for(int i=0; i<l; ++i) a1[i]=a[x+i];
    a1[l]='\0';
    if(strcmp(a1,b)) return 0;
    else return 1;
}
