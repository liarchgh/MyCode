#include<cstdio>
#include<list>
using namespace std;

int n,m[100000+5],ans=0xfffffff,jilu=-1,d[100000+5][2]={0},d1[100000+5][2]={0};
list<int>l[100000+5];
int zhao(int x);
int huan(int x,int a,int y,int b);

int main()
{
    int q,m,x;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&x);
            l[i].push_back(x);
        }
        zhao(i);
        //printf("%d\n",ans);
    }

    int a,y,b;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d",&x,&a,&y,&b);
        huan(x-1,a,y-1,b);
        printf("%d\n",ans);
    }
    return 0;
}
int zhao(int x)
{
    int a=-1;
    list<int>::iterator k=l[x].end();
    if(l[x].empty()) return 0;
    --k;
    while(k!=l[x].begin())
    {
        --a;
        if(a<*k) a=*k;
        //printf("%d\n",*k);
        --k;
    }
    --a;
    if(a<l[x].front()) a=l[x].front();
    d[x][0]=a;
    d[x][1]=a+l[x].size();
    for(int i=0;i<n;++i)
    {
        d1[i][0]=d[i][0];
        d1[i][1]=d[i][0];
    }
    for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
        if(d1[i][0]>d1[j][0])
    {
        int o=d1[i][0];
        d1[i][0]=d1[j][0];
        d1[j][0]=o;
        o=d[i][1];
        d1[i][1]=d1[j][1];
        d1[j][1]=o;
    }
    else if(d1[i][0]==d1[j][0])
        if(d1[i][1]<d1[j][1])
        {
        int o=d1[i][0];
        d1[i][0]=d1[j][0];
        d1[j][0]=o;
        o=d1[i][1];
        d1[i][1]=d1[j][1];
        d1[j][1]=o;
    }
    ans=d1[0][0];
    for(int i=0;i<n-1;++i)
        if(d[i][1]<d[i+1][0]) ans+=d[i+1][0]-d[i][1];
    //printf("%d\n",a);
    return 0;
}
int huan(int x,int a,int y,int b)
{
    list<int>::iterator k;
    list<int>::iterator k1=l[x].begin();
    list<int>::iterator k2=l[y].begin();
    for(int i=1;i<a;++i) ++k1;
    for(int i=1;i<b;++i) ++k2;
    for(int i=0;i<a;++i)
    {
        l[y].push_front(*k1);
        k=k1;
        if(k1!=l[x].begin()) --k1;
        l[x].erase(k);
    }
    for(int i=0;i<b;++i)
        {
        l[x].push_front(*k2);
        k=k2;
        if(k2!=l[y].begin()) --k2;
        l[y].erase(k);
    }
    zhao(x);
    zhao(y);
}
