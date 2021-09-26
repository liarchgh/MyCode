#include<cstdio>
#include<map>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    int N,m;
    char col[18],ans[18];
    while(scanf("%d",&N),N)
    {
        map<string,int>shu;
        m=0;
        getchar();
        while(N--)
        {
            gets(col);
            ++shu[col];
            if(shu[col]>m)
            {
                m=shu[col];
                strcpy(ans,col);
            }
        }
        puts(ans);
    }
    return 0;
}
