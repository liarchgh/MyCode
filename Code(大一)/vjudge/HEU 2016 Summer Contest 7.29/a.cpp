#include<cstdio>

const int inf=50005*13;
int n,t,a[inf];
int jianshu(int l,int r,int x);//区间l~r在下表为x处建立节点 顺便读入叶子结点的值
int gengxin(int l,int r,int x,int w,int z);//在下标为x处 区间为l~r 欲将w处加上z
int chaxun(int l,int r,int x,int zuo,int you);//位于……欲查询zuo~you区间的和
int main()
{
    char q[10];
    int x1,x2;
    scanf("%d",&t);
    for(int i=1; i<=t; ++i)
    {
        printf("Case %d:\n",i);
        int p=0;
        scanf("%d",&n);
        jianshu(1,n,1);
        getchar();
        /*int c=1,j=0;
        for(int i=1;i<=n*10;++i)
        {
                printf("%3d ",a[i]);
                ++j;
            if(c==j){j=0;putchar('\n');c*=2;}
        }*/
        while(1)
        {
            scanf("%s",q);
            switch(q[0])
            {
            case 'A':
                scanf("%d%d",&x1,&x2);
                getchar();
                gengxin(1,n,1,x1,x2);
                break;
            case 'S':
                scanf("%d%d",&x1,&x2);
                getchar();
                x2=-x2;
                gengxin(1,n,1,x1,x2);
                break;
            case 'Q':
                scanf("%d%d",&x1,&x2);
                getchar();
                printf("%d\n",chaxun(1,n,1,x1,x2));
                break;
            case 'E':
                p=1;
                break;
            }
            if(p) break;
        }
    }
    return 0;
}
int jianshu(int l,int r,int x)//区间l~r在下表为x处建立节点 顺便读入叶子结点的值
{
    if(l==r)
    {
        scanf("%d",&a[x]);
        //printf("%d  :%d\n",x,a[x]);
        return a[x];
    }
    int mid=(l+r)/2;
    a[x]=jianshu(l,mid,x*2)+jianshu(mid+1,r,x*2+1);
        //printf("%d  :%d\n",x,a[x]);
    return a[x];
}

int gengxin(int l,int r,int x,int w,int z)//在下标为x处 区间为l~r 欲将w处加上z
{
    a[x]+=z;
    if(l==r) return 0;
    int mid=(l+r)/2;
    if(mid>=w)
        gengxin(l,mid,x*2,w,z);
    else gengxin(mid+1,r,x*2+1,w,z);
    return 0;
}
int chaxun(int l,int r,int x,int zuo,int you)//位于……欲查询zuo~you区间的和
{
    //printf("%d %d %d %d\n",l,r,zuo,you);
    if(l>zuo || r<you || zuo>you) return 0;
    if(l==zuo && r==you) return a[x];
    int mid=(l+r)/2;
    if(mid>=zuo)
    {
        if(you<=mid) return chaxun(l,mid,x*2,zuo,you);
        else return chaxun(l,mid,x*2,zuo,mid)+chaxun(mid+1,r,x*2+1,mid+1,you);
    }
    else
    {
        return chaxun(mid+1,r,x*2+1,zuo,you);
    }
}
