#include<cstring>
#include<cstdio>

using namespace std;

int t,n,pos[9],deep;//记录任意一层已归纳到哪里 共有n个串 deep表示对最大层数的限制
char s[9][10],dna[4]= {'A','G','C','T'};
int dfs(int k);//前边已经有k层 成功归纳返回1 否则0
int sheng();//返回还未归纳的最多层数
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        getchar();
        for(int i=0; i<n; ++i)
        {
            gets(s[i]);
            s[i][9]=strlen(s[i]);
            //printf("%d %d\n",i,s[i][9]);
        }
        deep=sheng();
        memset(pos,0,sizeof(pos));
        while(!dfs(0))
        {
            ++deep;
            //printf("%d\n",deep);
        }//只要不成功就一直加深
        printf("%d\n",deep);
    }
    return 0;
}

int dfs(int k)
{
    int mx=sheng();
    if(k+mx>deep) return 0;
    if(!mx) return 1;
    int p1[n];
    for(int z=0; z<n; ++z) p1[z]=pos[z];
    for(int i=0; i<4; ++i)
    {
        int fl=0;
        for(int j=0; j<n; ++j)
        {
            if(pos[j]<s[j][9] && s[j][pos[j]]==dna[i])
            {
                fl=1;
                ++pos[j];
            }
        }
        if(fl)
        {
            if(dfs(k+1)) return 1;
            for(int z=0; z<n; ++z) pos[z]=p1[z];
        }
    }
    return 0;
}

int sheng()
{
    int m=0;
    for(int i=0; i<n; ++i)
    {
        m=m>s[i][9]-pos[i]?m:s[i][9]-pos[i];
    }
    return m;
}
