#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

stack<int>ans;
long long s[2][505];
int d[505][505],lu[505][505];
int main()
{
    int m[2];
    memset(d,0,sizeof(d));
    scanf("%d",&m[0]);
    for(int i=0; i<m[0]; ++i) scanf("%lld",&s[0][i]);
    scanf("%d",&m[1]);
    for(int i=0; i<m[1]; ++i) scanf("%lld",&s[1][i]);
    for(int i=0; i<m[0]; ++i)
    {
        for(int j=0; j<m[1]; ++j)
        {
            lu[i][j]=0;
            if(i>0 && d[i-1][j]>d[i][j])
            {
                d[i][j]=d[i-1][j];
                lu[i][j]=1;
            }
            if(j>0&&d[i][j]<d[i][j-1])
            {
                d[i][j]=d[i][j-1];
                lu[i][j]=2;
            }
            if(s[0][i]==s[1][j])
                if(i>0 && j>0)
                {
                    if(d[i][j]<d[i-1][j-1]+1)
                    {
                        d[i][j]=d[i-1][j-1]+1;
                        lu[i][j]=3;
                    }
                }
                else d[i][j]=1;
        }
    }
    int l1=m[0]-1,l2=m[1]-1;
    if(d[0][l1]==d[1][l2]) ans.push(d[0][l1]);
    while(lu[l1][l2])
    {
        switch(lu[l1][l2])
        {
        case 1:
            --l1;
            break;
        case 2:
            --l2;
            break;
        case 3:
            --l1;
            --l2;
            ans.push(s[0][l1+1]);
            break;
        }
    }
    if(s[0][l1]==s[1][l2]) ans.push(s[0][l1]);
    printf("%d\n",d[m[0]-1][m[1]-1]);
    if(d[m[0]-1][m[1]-1]==0) printf("\n\n");
    else
    {
        int a=ans.top();
        ans.pop();
        while(!ans.empty())
        {
            printf("%d ",a);
            a=ans.top();
            ans.pop();
        }
        printf("%d\n",a);
    }
    return 0;
}
