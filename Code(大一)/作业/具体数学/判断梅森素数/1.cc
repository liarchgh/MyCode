#include <cstdio>
#include <cstring>
int shu[1000],f[2000],l1,l2;
int a[1] = {2},b[1] = {1};
int cheng(int x[],int lx,int y[], int ly);
int jian(int x[],int lx, int y[], int ly);
int bidaxiao(int l1,int l2);
int pan(int n);
int main()
{
    int n = 19;
    memset(shu,0,sizeof(shu));
    memset(f,0,sizeof(f));
    f[0] = 4;
    shu[0]=1;
    if(pan(n))
        printf("Yes,it is.\n");
    else printf("No,it isn't\n");
    return 0;
}
int pan(int n)
{
    int x=n;
    l1=l2=1;
    while(x)
    {
        if(x % 2) l1=cheng(shu,l1,a,1);
        if(x >1) l1=cheng(shu,l1,shu,l1);
        x>>=1;
    }
    l1=jian(shu,l1,b,1);
    for(int i = 3; i <= n; ++i)
    {
        l2=cheng(f,l2,f,l2);
        jian(f,l2,a,1);
        while(bidaxiao(l1,l2))
            l2 = jian(f,l2,shu,l1);
    }
    if(!l2)
        return 1;
    else return 0;
}
int cheng(int x[],int lx,int y[],int ly)
{
    int l=lx,a[3000]= {0};
    for(int i=0; i<lx; ++i)
        for(int j=0; j<ly; ++j)
        {
            int d=i+j;
            a[d] += x[i] * y[j];
            if(d+1>l) l=d+1;
            for(int z=d; d<=z+2; ++d)
                if(a[d]>=10)
                {
                    a[d+1] = a[d]/10;
                    a[d]%=10;
                    if(d+2>l) l=d+2;
                }
        }
    memset(x,0,sizeof(x));
    for(int i=0; i<l; ++i)
        x[i] = a[i];
    return l;
}
int jian(int x[],int lx,int y[],int ly)
{
    for(int i=0; i<ly; ++i)
    {
        x[i]-=y[i];
    }
    for(int i=0; i<lx; ++i)
        while(x[i]<0)
        {
            x[i]+=10;
            --x[i+1];
        }
    while(!x[lx-1] && lx)
        --lx;
    return lx;
}
int bidaxiao(int l1,int l2)
{
    if(l2>l1) return 1;
    if(l2<l1) return 0;
    while(shu[l1-1] == f[l1-1] && l1>1)
    {
        --l1;
    }
    if(shu[l1-1] > f[l1-1]) return 0;
    else return 1;
}
