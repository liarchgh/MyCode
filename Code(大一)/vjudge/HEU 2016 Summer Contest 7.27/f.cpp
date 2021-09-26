#include<cstdio>
#include<queue>

using namespace std;

int su[1000]={0};
void suan();
queue<int>q;
int ch(int a,int b);
int main()
{
    int a,b;
    int n;
    suan();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&a,&b);
        if(a==b)
        {
            printf("0\n");
            continue;
        }
        ch(a,b);
    }
    return 0;
}

void suan()
{
    for(int x=2;x<=4000;++x)
    {
        int i,p=0;
        for(i=0;su[i];++i)
            if(!(x%su[i])) p=1;;
        if(p) continue;
        su[i]=x;
    }
}
int pan(int x)//回1是素数 0不是素数
{
    for(int i=0;i<500 && su[i]<=x/2;++i)
        if(!(x%su[i])) return 0;
    return 1;
}
int huan(int x,int i,int h)//将x中第i位变为h
{
    int a=0;i=5-i;
    while(i--){a=a*10+x%10;x/=10;}
    a=a/10*10+h;
    while(a) {x=x*10+a%10;a/=10;}
    while(x<1000) x*=10;
    return x;
}
int ch(int a,int b)
{
    int d[10000]={0};
    d[a]=1;
    q.push(a);
    while(!q.empty())
    {
        int x=q.front(),w;q.pop();
        for(int i=0;i<=9;++i)
        {
            for(int j=1;j<=4;++j)
            {
                if(!i && j==1) continue;
                w=huan(x,j,i);
                if(w==b)
                {
                    printf("%d\n",d[x]);
                    while(!q.empty()) q.pop();
                    return 1;
                }
                if(!d[w] && pan(w))
                {
                    d[w]=d[x]+1;
                    q.push(w);
                }
            }
        }
    }
}
