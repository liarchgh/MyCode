#include<cstdio>

const int mx=505;
int d[mx][mx][mx]= {1}; //d[i][j][k]=1 表示前i个硬币可组成j 选中的硬币可组成k
int main()
{
    int n,h,a;
    scanf("%d%d",&n,&h);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&a);
        for(int j=0; j<mx; ++j)
        {
            for(int k=0; k<mx; ++k)
            {
                if(!d[i][j][k]) continue;
                d[i+1][j][k]=1;
                if(j+a<=h)
                {
                    d[i+1][j+a][k]=1;
                    if(k+a<=h)
                        d[i+1][j+a][k+a]=1;
                }
            }
        }
    }
    int sum=0;
    for(int i=0; i<=h; ++i)
    {
        sum+=d[n][h][i];
    }
    printf("%d\n",sum);
    int i,x=0;
    for(i=0; i<=h; ++i)
    {

        if(d[n][h][i])
        {
            if(x==sum-1) break;
            printf("%d ",i);
            ++x;
        }
    }
    printf("%d\n",i);
    return 0;
}
