#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n,k,c[10][10],ans;
void zhao(int x);
vector<int>z;
int main()
{
    while(scanf("%d%d",&n,&k),n!=-1||k!=-1)
    {
        ans=0;
        //for(int i=0; i<n; ++i)
        //    for(int j=0; j<n; ++j) printf("%d ",d[i][j]);
        getchar();
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                switch(getchar())
                {
                case '.':
                    c[i][j]=0;
                    break;
                case '#':
                    c[i][j]=1;
                    break;
                }
            }
            getchar();
        }
        zhao(0);
        printf("%d\n",ans);
    }
    return 0;
}

void zhao(int x)
{
    if(x>=n) return;
    for(int i=0; i<n; ++i)
    {
        if(c[x][i] && find(z.begin(),z.end(),i)==z.end())
        {
            z.push_back(i);
            if(z.size()==k) ++ans;
            else zhao(x+1);
            z.erase(z.end()-1);
        }
    }
    zhao(x+1);
}
