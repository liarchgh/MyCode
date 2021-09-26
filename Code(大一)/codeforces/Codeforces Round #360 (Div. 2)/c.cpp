#include<cstdio>
#include<vector>
using namespace std;

const int mx=10e5+5;
vector<int> a[mx];//动态数组的数组
int m,n,d[mx]= {0},sum[3]= {0},geshu=0;
int cha(int x,int vx);//返回值为1表示成功 0表示失败 将结点x赋值为vx
int main()
{
    int c,b;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
    {
        scanf("%d%d",&c,&b);
        if(a[c].empty()) ++geshu;//读入的结点还没读过的话 总结点数+1
        if(a[b].empty()) ++geshu;
        a[c].push_back(b);//互相向对方的子节点堆里加入自己
        a[b].push_back(c);
    }
    int p=1;
    for(int i=1; i<=n; ++i)//注意 有可能有多个网络
    {
        if(!d[i] && a[i].size())
            if(!cha(i,1))
            {
                p=0;break;
            }
    }
    if(!p) printf("-1\n");//将第一个节点归入结点集1 开始
    else
    {
        int c[3]= {0};
        for(int j=1; j<=2; ++j)
        {
            printf("%d\n",sum[j]);//先输出此结点集的节点个数
            int i;
            for(i=1; i<=n; ++i)//一个一个节点扫
                if(d[i]==j)
                {
                    ++c[j];
                    if(c[j]>=sum[j]) break;//到达最后一个就退出循环
                    printf("%d ",i);
                }
            printf("%d\n",i);
        }
    }
    return 0;
}

int cha(int x,int vx)
{
    if(!d[x])//还没有赋值
    {
        d[x]=vx;
        ++sum[vx];//结点集总数+1
        vector<int>::iterator it;
        for(it=a[x].begin(); it!=a[x].end(); ++it)//遍历它的子节点
        {
            if(!cha(*it,3-vx))
                return 0;
        }
        return 1;
    }
    else//赋值过了
    {
        if(vx!=d[x]) return 0;
        else return 1;
    }
}
