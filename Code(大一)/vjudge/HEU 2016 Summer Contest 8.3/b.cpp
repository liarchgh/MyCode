#include<cstdio>
#include<algorithm>

using namespace std;

int a[305],//d[x][y]��ǰx����ׯ��y���ʾֵ���̾���
    dis[305][305]= {0};//dis[x][y]Ϊx��y��ׯ�е��ܾ�����С���ʾֵ��ܾ���
long long d[305][35]= {0};
//int mx=0;
long long juli(int a,int b);//����a��b���ж������ʾֵ��ܾ���
int main()
{
    int v,p;
    scanf("%d%d",&v,&p);
    for(int i=0; i<v; ++i)
    {
        scanf("%d",&a[i]);
        //if(a[i]>mx) mx=a[i];
    }
    sort(a,a+v);
    for(int j=1; j<=p; ++j)  //��ǰ��Ϊֹһ����j���ʾ�
    {
        for(int u=j+1; u<=v; ++u)  //��ǰu����ׯ��˵
        {
            long long x=0xffffffffffffff;
            for(int i=j-1; i<u; ++i)  //��ǰj-1���ʾַ���ǰi����ׯ
            {
                x=min(x,d[i][j-1]+juli(i+1,u));
                //printf("%d %lld\n",u,d[2][1]);
            }
            if(j==1) d[u][j]=juli(1,u);
            else
                d[u][j]=x;
            //printf("%lld\n",x);
        }
    }
    printf("%lld\n",d[v][p]);
    return 0;
}

long long juli(int c,int b)//����c��b���ж������ʾֵ��ܾ���
{
    if(dis[c][b]) return dis[c][b];
    int x=(c+b)/2,t;
    long long sum=0;
    for(int i=c; i<=b; ++i)
    {
        t=a[i]-a[x];
        if(t<0) t=-t;
        sum+=t;
    }
    dis[c][b]=sum;
    //printf("%d %d %lld\n",c,b,sum);
    return sum;
}
