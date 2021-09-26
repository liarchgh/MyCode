#include<cstdio>
#include<queue>
using namespace std;

queue<int>q;
const int inf=500005;
int d[inf]= {0},n,k;
int suan(int x,int i);
int main()
{
    scanf("%d%d",&n,&k);
    q.push(n);d[n]=1;
    if(n==k) {printf("0\n");return 0;}
    while(!q.empty())
    {
        int x,x1=q.front();q.pop();
        for(int i=0; i<3; ++i)
        {
            x=suan(x1,i);
            //printf("%d ",x);
            if(x==k)
            {
                printf("%d\n",d[x1]);
                return 0;
            }
            else if(x>=0 && x<=inf && !d[x])
            {
                d[x]=d[x1]+1;
                q.push(x);
            }
        }
    }
    return 0;
}
int suan(int x,int i)
{
    switch(i)
    {
    case 0:
        return x+x;
    case 1:
        return x+1;
    case 2:
        return x-1;
    }
}
