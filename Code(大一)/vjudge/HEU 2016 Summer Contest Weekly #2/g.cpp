#include<cstdio>

long long int n,q,a[2000005],d[2000005]={0};
long long int jianshu(long long int l,long long int r,long long int x);
long long int he(long long int x);
void jia(long long int l,long long int r,long long int x,long long int cl,long long int cr,long long int c);//区间加
void pushdown(long long int l,long long int r,long long int x);//将加的向下推一层
long long int cha(long long int l,long long int r,long long int x,long long int ql,long long int qr);
int main()
{
    scanf("%lld%lld",&n,&q);
    //printf("        %d\n",q);
    jianshu(1,n,1);getchar();
    long long int e,b,c;
    for(int i=0;i<q;++i)
    {
        switch(getchar())
        {
        case 'Q':scanf("%lld%lld",&b,&c);
            printf("%d\n",cha(1,n,1,b,c));
            break;
        case 'C':scanf("%lld%lld%lld",&e,&b,&c);
            jia(1,n,1,e,b,c);
            break;
        }
        getchar();
    }
    return 0;
}
long long int jianshu(long long int l,long long int r,long long int x)
{
    if(l==r){scanf("%lld",&a[x]);return 0;}
    long long int mid=(l+r)>>1;
    jianshu(l,mid,x*2);
    jianshu(mid+1,r,x*2+1);
    he(x);
    //printf("%d %d %d %d\n",l,r,x,a[x]);
}
long long int he(long long int x)
{
    a[x]=a[x*2]+a[x*2+1];
    return 0;
}
void jia(long long int l,long long int r,long long int x,long long int cl,long long int cr,long long int c)//区间加
{
    if(d[x])
    {
        pushdown(l,r,x);
    }
    if(l>=cl && r<=cr)
    {
        d[x]=c;
        pushdown(l,r,x);
        return ;
    }
    if(l>cr || r<cl) return ;
    long long int mid=(l+r)>>1;
    jia(l,mid,x*2,cl,cr,c);
    jia(mid+1,r,x*2+1,cl,cr,c);
    he(x);
}
void pushdown(long long int l,long long int r,long long int x)//将加的向下推一层
{
    a[x]+=d[x]*(l-r+1);
    d[x*2]=d[x*2+1]=d[x];
    d[x]=0;
}

long long int cha(long long int l,long long int r,long long int x,long long int ql,long long int qr)
{//printf("%d %d %d\n",l,r,x);
    if(d[x])
        pushdown(l,r,x);
    if(l>=ql && r<=qr) return a[x];
    if(l>qr && r<ql) return 0;
    if(l==r) return 0;
    long long int mid=(l+r)>>1;
    return cha(l,mid,x*2,ql,qr)+cha(mid+1,r,x*2+1,ql,qr);
}
