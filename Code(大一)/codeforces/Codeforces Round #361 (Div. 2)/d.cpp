//学习rmq算法 第二次使用二分法
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=200005;
int ma[maxn][25],mb[maxn][25],n;
__int64 sum=0;
void rmq()//rmq算法 先用二次方将总的情况分开 在查询
{
    for(int j=1;1<<j<=n;++j)
    {
        for(int i=0;i+(1<<j)-1<n;++i)
        {
            if((i+(1<<j)-1)<=n)
            {
                ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
                mb[i][j]=min(mb[i][j-1],mb[i+(1<<(j-1))][j-1]);
    //printf("%d %d %d %d\n",i,j,ma[i][j],mb[i][j]);
            }
        }
    }
}
int zhao(int l,int r)
{
    int i=log((r-l+1)*1.0)/log(2.0),a,b;
    a=max(ma[l][i],ma[r-(1<<i)+1][i]),
        b=min(mb[l][i],mb[r-(1<<i)+1][i]);
        //printf("%d %d %d %d\n",l,r,a,b);
    if(a<b) return 1;
    else if(a>b) return -1;
    return 0;
}
int pan(int l)//据说是用了二分法查找 在相等时找上下限的情况是不同的 并不慢
{
    int r1=-1,r2=-1,i,j;
    for(i=l,j=n-1;i<=j;)
    {
        int mid = (i+j)/2;
        switch(zhao(l,mid))
        {
            case 0:r1=mid;
            case -1:j=mid-1;break;
            default:i=mid+1;
        }
    }
    if(r1==-1) return 0;
    //while(zhao(l,j)) ++j;

    for(i=l,j=n-1;i<=j;)
    {
        int mid = (i+j)/2;
        switch(zhao(l,mid))
        {
            case 0:r2=mid;
            case 1:i=mid+1;break;
            default:j=mid-1;
        }
    }
    //while(zhao(l,i)) --i;
    //printf("%d %d\n",r1,r2);
    return r2-r1+1;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&ma[i][0]);
    }
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&mb[i][0]);
    }
    rmq();
    //for(int j=0;j<n;++j)
    //for(int i=0;i<18;++i)
    //    printf("%d %d %d %d\n",i,j,ma[i][j],mb[i][j]);
    for(int l=0; l<n; ++l)
    {
        sum+=pan(l);
    }
    printf("%I64d\n",sum);
    return 0;
}
