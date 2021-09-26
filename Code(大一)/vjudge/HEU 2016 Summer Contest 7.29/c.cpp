#include<cstdio>

const long long int inf=4000005;
int h,w,n,a[inf];
int chong(int l,int r,int x,int t);//在区间为l~r 下标为x的范围内查找能容下t的位置 同时对其孩子结点及其自身进行更新
int main()
{
    while(scanf("%d",&h)!=EOF)
    {
        int t;
        scanf("%d%d",&w,&n);
        if(h>n) h=n;//注意最大为10e9 而h在大于n时 下标大于n的结点是不会用到的 而h如果不缩小 在递归时就可能数组越界
        for(int i=0; i<inf; ++i) a[i]=w;
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&t);
            chong(1,h,1,t);
        }
    }
    return 0;
}

int chong(int l,int r,int x,int t)
{
    //printf("%d %d %d %d\n",l,r,x,a[x]);
    if(x==1 && a[1]<t)
    {
        printf("-1\n");
        return 0;//直接在1节点处判断出是否成功
    }
    if(l==r)
    {
        a[x]-=t;
        printf("%d\n",l);
        return a[x];
    }
    int mid=(l+r)/2;
    if(a[x*2]>=t)
    {
        int m=chong(l,mid,x*2,t);
        a[x]=a[x*2+1]>m?a[x*2+1]:m;
        return a[x];
    }
    else
    {
        int m=chong(mid+1,r,x*2+1,t);
        a[x]=a[x*2]>m?a[x*2]:m;
        return a[x];
    }
}
