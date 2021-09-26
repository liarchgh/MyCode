#include<cstdio>

const long long int inf=4000005;
int h,w,n,a[inf];
int chong(int l,int r,int x,int t);//������Ϊl~r �±�Ϊx�ķ�Χ�ڲ���������t��λ�� ͬʱ���亢�ӽ�㼰��������и���
int main()
{
    while(scanf("%d",&h)!=EOF)
    {
        int t;
        scanf("%d%d",&w,&n);
        if(h>n) h=n;//ע�����Ϊ10e9 ��h�ڴ���nʱ �±����n�Ľ���ǲ����õ��� ��h�������С �ڵݹ�ʱ�Ϳ�������Խ��
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
        return 0;//ֱ����1�ڵ㴦�жϳ��Ƿ�ɹ�
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
