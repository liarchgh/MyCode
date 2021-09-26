#include<cstdio>
int main()
{
    __int64 m,n,sha[25][25]={0};
    for(int i=1;i<21;++i)
        sha[i][1]=i;
    for(int i=2;i<21;++i)
    {
        for(int j=i;j<=20;++j)
            {
                sha[j][i]=sha[j][i-1]+sha[j-1][i];
            }
    }
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        printf("%I64d\n",sha[m][n]);
    }
    return 0;
}
