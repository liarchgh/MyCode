#include<cstdio>
#include<cstring>
int shu[8010][655] = {{1},{1},{1},{1}};
void suan()
{
    memset(shu[4],0,8000*sizeof(shu[4]));
    int w=1;
    for(int i=4;i<8000;++i)
    {
        int j;
        for(j=0;(shu[i-1][j] || j<=w) && j<=650;++j)
        {
            shu[i][j] += shu[i-1][j]+shu[i-2][j]+shu[i-3][j]+shu[i-4][j];
            if(shu[i][j]>9999)
            {
                shu[i][j+1]=shu[i][j]/10000;
                shu[i][j] %= 10000;
            }
        }
        w=(j>w)?j:w;
        //if(w>650) break;
    }
}
int main()
{
    suan();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int w;
        for(w=650;w>=0;--w) if(shu[n-1][w]) break;
        printf("%d",shu[n-1][w--]);
        for(;w>=0;--w)
            printf("%04d",shu[n-1][w]);
        putchar('\n');
    }
    return 0;
}
