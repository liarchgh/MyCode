#include<cstdio>
#include<cstring>

const int inf=2000005;
int n,a[inf],z[inf];
int huan(int l,int r,int x,int ql,int qr,int q);//将区间ql~qr的部分价值置换为q
int pushup(int x);//更新一次
int pushdown(int l,int r,int x);//把标记向下压一层
int build(int l,int r,int x);//将区间l~r设置为1 并计算此时的价值和
int main()
{
    int q,t,x,y,c;
    scanf("%d",&t);
    for(int u=1; u<=t; ++u)
    {
        scanf("%d%d",&n,&q);
        memset(z,0,sizeof(z));
        build(1,n,1);
        for(int i=1; i<=q; ++i)
        {
            scanf("%d%d%d",&x,&y,&c);
            //printf("%d\n",c);
            huan(1,n,1,x,y,c);
        }
        //for(int j=1; j<31; ++j) printf("%d %d\n",j,z[j]);
        printf("Case %d: The total value of the hook is %d.\n",u,a[1]);
    }
    return 0;
}

int huan(int l,int r,int x,int ql,int qr,int q)//将区间l~r中的ql~qr的部分价值置换为q
{
    if(l>=ql && r<=qr)
    {
        z[x]=q;
        pushdown(l,r,x);
        return 0;
    }
    pushdown(l,r,x);
    if(r<ql || l>qr) return 0;
    if(l==r)
    {
        a[x]=q;
        z[x]=0;
        return 0;
    }
    //printf("%d %d %d\n",l,r,x);
    if(l==r)
    {
        a[x]=q;
        z[x]=0;
        return 0;
    }
    int mid=(l+r)/2;
    huan(l,mid,x*2,ql,qr,q);
    huan(mid+1,r,x*2+1,ql,qr,q);
    pushup(x);
    //printf("%d %d %d %d\n",l,r,a[x*2],a[x*2+1]);
    return 0;
}

int build(int l,int r,int x)//将区间l~r设置为1 并计算此时的价值和
{
    if(l==r)
    {
        a[x]=1;
        return 1;
    }
    int mid=(l+r)/2;
    a[x]=r-l+1;
    build(l,mid,x*2)+build(mid+1,r,x*2+1);
    return 1;
}
int pushup(int x)
{
    return a[x]=a[x*2]+a[x*2+1];
}
int pushdown(int l,int r,int x)
{
    if(z[x])
        if(l!=r)
        {
            z[x<<1]=z[x<<1|1]=z[x];
            a[x]=z[x]*(r-l+1);
            z[x]=0;
        }
        else
        {
            a[x]=z[x];
            z[x]=0;
        }
    return a[x];
}
/*
#define N 112345
#define root 1 , n , 1
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1

int  sum[N<<2],add1[N<<2];
void pushUp(int rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}
void pushDown1(int l,int r,int rt)
{
    if(add1[rt])
    {
        int m = (l+r)>>1;
        add1[rt<<1] = add1[rt<<1|1] = add1[rt];
        sum[rt<<1] = (m-l+1)*add1[rt];
        sum[rt<<1|1] = (r-m)*add1[rt];
        add1[rt] = 0;
    }
}
void update1(int l,int r,int rt,int ql,int qr,int val)
{
    if(l>qr||ql>r)return;
    if(l>=ql&&r<=qr)
    {
        sum[rt] = (r-l+1)*val;
        add1[rt] = val;
        return;
    }
    pushDown1(l,r,rt);
    int m = (l+r)>>1;
    if(ql<=m)update1(lson,ql,qr,val);
    if(qr>m)update1(rson,ql,qr,val);
    pushUp(rt);
}
//建树
void build(int l,int r,int rt)
{
    add1[rt]=0;
    if(l == r)
    {
        sum[rt] = 1;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}
//区间和询问
int query(int l,int r,int rt,int ql,int qr)
{
    if(l>qr||ql>r)
        return 0;
    if(l>=ql&&r<=qr)
        return sum[rt];
    pushDown1(l,r,rt);
    int m = l+r>>1;
    return query(l,m,rt<<1,ql,qr)+query(m+1,r,rt<<1|1,ql,qr);
}

int main()
{
    int i,j,k,kk,t,x,y,res,ans;
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
    scanf("%d",&k);
    kk=0;
    while(k--)
    {
        scanf("%d%d",&n,&m);
        build(root);
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d",&x,&y,&t);
            update1(root,x,y,t);
        }
        printf("Case %d: The total value of the hook is %d.\n",++kk,sum[1]);
    }
    return 0;
}
*/
