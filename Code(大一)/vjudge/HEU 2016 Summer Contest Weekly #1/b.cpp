#include<cstdio>

const int inf=100005;
int n,a[inf];
int jianshu(int l,int r,int x);//建树区间l~r 结点x
int chaxun(int l,int r, int x,int ql,int qr);//查询区间ql~qr的最大值
int main()
{
    int t,q,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        jianshu(1,n,1);
        scanf("%d",&q);
        //for(int i=1;i<10;++i) printf("%d %d\n",i,a[i]);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",chaxun(1,n,1,l,r));
        }
    }
    return 0;
}

int jianshu(int l,int r,int x)
{
    if(l==r)
    {
        scanf("%d",&a[x]);
        return a[x];
    }
    int mid=(l+r)/2;
    int al=jianshu(l,mid,x*2),ar=jianshu(mid+1,r,x*2+1);
    a[x]=al>ar?al:ar;
    return a[x];
}

int chaxun(int l,int r, int x,int ql,int qr)
{
    if(l==ql && r==qr) return a[x];
    int mid=(l+r)/2;
    if(ql<=mid)
    {
        if(qr<=mid)
        {
            return chaxun(l,mid,x*2,ql,qr);
        }
        else
        {
            int al=chaxun(l,mid,x*2,ql,mid),ar=chaxun(mid+1,r,x*2+1,mid+1,qr);
            return al>ar?al:ar;
        }
    }
    else
    {
        return chaxun(mid+1,r,x*2+1,ql,qr);
    }
}
